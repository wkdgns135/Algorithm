#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] += 2;
        dp[i] %= 1000000007;
    }
    cout << dp[n];
}
