#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i][i] = true; 
    }

    for (int i = 1; i < n; i++) {
        if (v[i] == v[i + 1]) dp[i][i + 1] = true;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            if (v[i] == v[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    cin >> m;
    while (m--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
}
