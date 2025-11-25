#include <bits/stdc++.h>
using namespace std;

int main() {
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

    map<string, map<string, string>> table;
    for (auto &entry : grammar) {
        string A = entry.first;
        for (auto &prod : entry.second) {
            string rhs = "";
            for (string s : prod) rhs += s;

            if (prod.size() == 1 && prod[0] == "ε")
                prod[0] = "eps";

            if (prod.size() == 1 && prod[0] == "eps") {
                for (string a : FOLLOW[A])
                    table[A][a] = "eps";
                continue;
            }

            string firstSym = prod[0];
            if (!isupper(firstSym[0]))
                table[A][firstSym] = rhs;
            else {
                for (string t : FIRST[firstSym]) {
                    if (t != "eps")
                        table[A][t] = rhs;
                    else
                        for (string a : FOLLOW[A])
                            table[A][a] = rhs;
                }
            }
        }
    }

    cout << "\nLL(1) Parsing Table:\n";
    for (auto &row : table) {
        string A = row.first;
        for (auto &col : row.second)
            cout << "M[" << A << ", " << col.first << "] = "
                 << A << " -> " << col.second << "\n";
    }

    return 0;
}
