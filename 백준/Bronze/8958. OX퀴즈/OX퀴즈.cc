#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int answer = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O') answer += ++count;
            else count = 0;
        }
        cout << answer << '\n';
    }
}
