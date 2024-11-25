#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;

    for (char c = 'a'; c <= 'z'; c++) {
        auto pos = find(s.begin(), s.end(), c);
        if (pos == s.end()) cout << "-1" << ' ';
        else cout << pos - s.begin() << ' ';
    }
}
