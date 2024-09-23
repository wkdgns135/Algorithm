#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n), dp(n + 1); for (int i = 0; i < n; i++) cin >> v[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1, count = 1; j <= n; j += i + 1, count++) {
            dp[j] = max(dp[j], v[i] * count);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + 1 + j <= n; j++) {
            if (i == j) continue;
            dp[i + 1 + j] = max(dp[i + 1 + j], dp[i + 1] + dp[j]);
        }
    }

    for (int i = n-1; i > 0; i--) {
        dp[i + 1] = max(dp[i + 1], dp[i] + dp[n - i]);
    }

    cout << dp[n];
}