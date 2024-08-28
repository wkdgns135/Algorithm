#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3));
    
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
    dp[0][0] = v[0][0], dp[0][1] = v[0][1], dp[0][2] = v[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
    }
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
