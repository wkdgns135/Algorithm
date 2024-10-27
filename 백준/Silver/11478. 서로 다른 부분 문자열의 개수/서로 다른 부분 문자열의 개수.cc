#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    unordered_map<string, bool> m;
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= s.size() - i; j++) {
            string str = s.substr(i, j);
            answer += !m[str];
            m[str] = true;
        }
    }
    cout << answer;
}
