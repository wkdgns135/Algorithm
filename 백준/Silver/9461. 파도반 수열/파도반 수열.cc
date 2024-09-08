#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    vector<long long> dp(101);
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= 100; i++) dp[i] = dp[i - 2] + dp[i - 3];
   
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}
