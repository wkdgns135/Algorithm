#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<bool> dp(1001);
    dp[1] = false, dp[2] = true, dp[3] = false, dp[4] = true;
    for (int i = 5; i < 1001; i++) dp[i] = dp[i - 4];
    cout << (dp[n] ? "CY" : "SK");
}
