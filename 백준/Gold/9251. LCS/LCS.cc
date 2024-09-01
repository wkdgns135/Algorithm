#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

    int answer = 0;
    for (int i = 1; i <= a.size(); i++) {
        int maxNum = 0;
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = maxNum + 1;
                answer = max(dp[i][j], answer);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
            maxNum = max(dp[i - 1][j], maxNum);
        }
    }

    cout << answer;
}
