#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    stack<char> s;
    int answer = 0;
    char pre = ' ';
    for (char& c : str) {
        if (c == '(') s.push('(');
        else {
            if (pre == '(') answer += s.size() - 1;
            else answer++;
            s.pop();
        }
        pre = c;
    }
    cout << answer;
}