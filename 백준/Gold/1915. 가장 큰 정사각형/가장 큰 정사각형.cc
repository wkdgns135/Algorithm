#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n, m; cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(m));
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
        {
            int num = s[j] - '0';
            v[i][j] = num;
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == false)continue;
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
                answer = max(answer, dp[i][j]);
                continue;
            }
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer * answer;
}