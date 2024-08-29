#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<vector<int>> v(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < n; i++)cin >> v[0][i];
        for (int i = 0; i < n; i++)cin >> v[1][i];

        if (n == 1) { cout << max(v[0][n - 1], v[1][n - 1]) << '\n'; continue; }

        dp[0][0] = v[0][0], dp[1][0] = v[1][0];
        dp[0][1] = v[1][0] + v[0][1], dp[1][1] = v[0][0] + v[1][1];
        for (int i = 2; i < n; i++) {
            dp[0][i] = v[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = v[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

}
