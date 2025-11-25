#include <bits/stdc++.h>
using namespace std;

int main() {
    // -----------------------------
    // Input grammar
    // -----------------------------
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();

    map<string, vector<vector<string>>> grammar;

    cout << "Enter productions (format: A -> α | β ...):\n";
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        string lhs = line.substr(0, line.find("->") - 1);
        string rhs = line.substr(line.find("->") + 3);

        stringstream ss(rhs);
        string part;

        while (getline(ss, part, '|')) {
            stringstream ss2(part);
            string symbol;
            vector<string> prod;
            while (ss2 >> symbol)
                prod.push_back(symbol);
            grammar[lhs].push_back(prod);
        }
    }

    // -----------------------------
    // Input FIRST sets
    // -----------------------------
    int f1;
    cout << "Enter number of FIRST sets: ";
    cin >> f1;
    cin.ignore();

    map<string, set<string>> FIRST;
    cout << "Enter FIRST sets (format: A -> a b ;):\n";
    for (int i = 0; i < f1; i++) {
        string nt, arrow, x;
        cin >> nt >> arrow;
        while (cin >> x && x != ";")
            FIRST[nt].insert(x);
    }

    // -----------------------------
    // Input FOLLOW sets
    // -----------------------------
    int f2;
    cout << "Enter number of FOLLOW sets: ";
    cin >> f2;
    cin.ignore();

    map<string, set<string>> FOLLOW;
    cout << "Enter FOLLOW sets (format: A -> a b ;):\n";
    for (int i = 0; i < f2; i++) {
        string nt, arrow, x;
        cin >> nt >> arrow;
        while (cin >> x && x != ";")
            FOLLOW[nt].insert(x);
    }

    // -----------------------------
    // Construct LL(1) parsing table
    // -----------------------------
    map<string, map<string, string>> table;

    for (auto &entry : grammar) {
        string A = entry.first;  // Non-terminal

        for (auto &prod : entry.second) {
            // Combine RHS symbols into a string
            string rhs = "";
            for (string s : prod) rhs += s;

            // Case 1: production is epsilon
            if (prod.size() == 1 && prod[0] == "ε") {
                for (string a : FOLLOW[A])
                    table[A][a] = "ε";
                continue;
            }

            string firstSym = prod[0];

            // Case 2: first symbol is terminal
            if (!isupper(firstSym[0])) {
                table[A][firstSym] = rhs;
            }
            // Case 3: first symbol is non-terminal
            else {
                for (string t : FIRST[firstSym]) {
                    if (t != "ε")
                        table[A][t] = rhs;
                    else
                        // if ε in FIRST, add for FOLLOW(A)
                        for (string a : FOLLOW[A])
                            table[A][a] = rhs == "ε" ? "ε" : rhs;
                }
            }
        }
    }

    // -----------------------------
    // Print parsing table
    // -----------------------------
    cout << "\nLL(1) Parsing Table:\n";
    for (auto &row : table) {
        string A = row.first;
        for (auto &col : row.second) {
            cout << "M[" << A << ", " << col.first << "] = "
                 << A << " -> " << col.second << "\n";
        }
    }

    return 0;
}
