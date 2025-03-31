#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int k = i + j;

            if (i == 1)
            {
                dp[j][k] = v[j][0] * v[k][0] * v[k][1];
                continue;
            }
            dp[j][k] = INT_MAX;
            for (int l = j; l < k; l++)
            {
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l + 1][k] + v[j][0] * v[l][1] * v[k][1]);
            }
        }
    }
    cout << dp[0][n - 1];
}