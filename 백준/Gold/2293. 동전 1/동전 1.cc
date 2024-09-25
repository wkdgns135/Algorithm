#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[k];
}