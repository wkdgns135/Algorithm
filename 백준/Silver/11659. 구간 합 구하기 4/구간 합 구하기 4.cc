#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    while (m--) {
        int i, j; cin >> i >> j;
        cout << v[j] - v[i-1] << '\n';
    }
}