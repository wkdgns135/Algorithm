#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<string, int> before, after;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            before[s]++;
        }
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            after[s]++;
        }
        cout << (before == after ? "NOT CHEATER" : "CHEATER") << '\n';
    }
}
