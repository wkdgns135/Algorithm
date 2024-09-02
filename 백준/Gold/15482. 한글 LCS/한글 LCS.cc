#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() +1));

    for (int i = 3; i <= a.size(); i+=3) {
        for (int j = 3; j <= b.size(); j+=3) {
            if (a.substr(i - 3, 3) == b.substr(j - 3, 3)) dp[i][j] = dp[i - 3][j - 3] + 1;
            else dp[i][j] = max(dp[i][j - 3], dp[i - 3][j]);
        }
    }

    cout << dp[a.size()][b.size()];
}
