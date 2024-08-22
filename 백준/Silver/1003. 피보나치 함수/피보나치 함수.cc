#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    vector<pair<int, int>> v(41);
    v[0].first = 1; v[1].second = 0;

    for (int i = 1; i <= 40; i++) {
        v[i].first = v[i - 1].second;
        v[i].second = v[i - 1].first + v[i - 1].second;
    }
    while (t--) { int n; cin >> n; cout << v[n].first << ' ' << v[n].second << '\n'; }
}