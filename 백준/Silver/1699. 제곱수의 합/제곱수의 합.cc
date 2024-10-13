#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i <= n; i++) {
        for (int j = i * i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }
    cout << dp[n];
}
