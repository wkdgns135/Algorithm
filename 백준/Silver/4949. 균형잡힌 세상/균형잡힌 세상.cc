#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    string str = ""; getline(cin, str);
    while (str != ".") {
        string result = "yes";
        stack<char> s;
        for (char &c : str) {
            if (c == '(' || c == '[')s.push(c);
            if (c == ')') {
                if (!s.empty() && s.top() == '(')s.pop();
                else { result = "no"; break; }
            }
            if (c == ']') {
                if (!s.empty() && s.top() == '[')s.pop();
                else { result = "no"; break; }
            }
        }
        if (!s.empty())result = "no";
        cout << result << '\n';
        getline(cin, str);
    }
}
