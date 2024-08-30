#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> v(n);
    vector<vector<int>> dp(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int input; cin >> input;
            v[i].push_back(input);
            dp[i].push_back(0);
        }
    }

    dp[0][0] = v[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int left = j - 1 < 0 ? 0 : dp[i - 1][j - 1];
            int right = j == v[i-1].size() ? 0 : dp[i - 1][j];
            dp[i][j] = v[i][j] + max(left, right);
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
}
