#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> coins(n);
		for (int i = 0; i < n; i++) cin >> coins[i];
		int m; cin >> m;

		vector<int> dp(m + 1, 0);
		dp[0] = 1;

		for (int coin : coins)
		{
			for (int j = coin; j <= m; j++)
			{
				dp[j] += dp[j - coin];
			}
		}

		cout << dp[m] << '\n';
	}
}

