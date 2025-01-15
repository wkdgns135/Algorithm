#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    stack<char> oper;
    unordered_map<char, int> priority = { {'+',0},{'-', 0}, {'*',1},{'/',1} };

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') {
            cout << ch;
        }
        else if (ch == '(') {
            oper.push(ch);
        }
        else if (ch == ')') {
            while (!oper.empty() && oper.top() != '(') {
                cout << oper.top();
                oper.pop();
            }
            oper.pop();
        }
        else {
            if (oper.empty()) {
                oper.push(ch);
            }
            else {
                while (!oper.empty() && oper.top() != '(' && priority[oper.top()] >= priority[ch]) {
                    cout << oper.top();
                    oper.pop();
                }
                oper.push(ch);
            }
        }
    }
    while (!oper.empty()) {
        cout << oper.top();
        oper.pop();
    }
}
