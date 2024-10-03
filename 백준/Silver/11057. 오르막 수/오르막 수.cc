#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(10, 1));
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 10; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= 10007;
        }
    }
    cout << accumulate(dp[n].begin(), dp[n].end(), 0) % 10007;

}
