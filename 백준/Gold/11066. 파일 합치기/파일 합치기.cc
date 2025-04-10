#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        vector<int> subtotal(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            subtotal[i] = subtotal[i - 1] + arr[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int start = 0; start <= n - len; ++start)
            {
                int end = start + len - 1;
                for (int mid = start; mid < end; ++mid)
                {
                    dp[start][end] = min(dp[start][end],
                        dp[start][mid] + dp[mid + 1][end] + subtotal[end + 1] - subtotal[start]);
                }
            }
        }

        cout << dp[0][n - 1] << '\n';
    }
}
