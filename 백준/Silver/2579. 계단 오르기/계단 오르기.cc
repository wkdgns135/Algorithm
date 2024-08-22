#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n), dp(n);
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
        total += v[i];
    }
    dp[0] = v[0];
    dp[1] = v[1] + v[0];
    dp[2] = max(v[0] + v[2], v[1] + v[2]);

    for (int i = 3; i < v.size(); i++){
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }
    cout << dp[n - 1];
}