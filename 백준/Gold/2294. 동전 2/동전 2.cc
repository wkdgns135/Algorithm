#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> coins(n); for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(k + 1, 10001);
    for (auto &coin : coins)if (coin <= k)dp[coin] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < i; j++) {
            if (i - j == 0)continue;
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }

    if (dp[k] == 10001)cout << -1;
    else cout << dp[k];
}