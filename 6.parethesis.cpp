#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosing(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    string filename;
    cout << "Enter C filename: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    stack<char> s;
    string line;
    bool inBlockComment = false;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        for (size_t i = 0; i < line.size(); i++) {


            if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i+1] == '*') {
                inBlockComment = true;
                i++;
                continue;
            }


            if (inBlockComment && i + 1 < line.size() && line[i] == '*' && line[i+1] == '/') {
                inBlockComment = false;
                i++;
                continue;
            }

            if (inBlockComment) continue;


            if (i + 1 < line.size() && line[i] == '/' && line[i+1] == '/') {
                break;
            }

            char c = line[i];

            if (isOpening(c)) s.push(c);
            else if (isClosing(c)) {
                if (s.empty() || !matches(s.top(), c)) {
                    cout << "Unmatched '" << c << "' at line " << lineNumber << endl;
                    return 1;
                }
                s.pop();
            }
        }
    }

    if (s.empty())
        cout << "All parentheses/brackets are balanced." << endl;
    else
        cout << "Unmatched opening parentheses/brackets remain." << endl;

    file.close();
    return 0;
}
