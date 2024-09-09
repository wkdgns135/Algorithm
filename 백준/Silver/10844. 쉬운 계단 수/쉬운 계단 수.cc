#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 1));
    int answer = 9;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][1];
            else if (j == 9) dp[i][j] = dp[i - 1][8];
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= 1000000000;
        }
        answer = accumulate(dp[i].begin() + 1, dp[i].end(), (long long)0) % 1000000000;
    }
    cout << answer;
}
