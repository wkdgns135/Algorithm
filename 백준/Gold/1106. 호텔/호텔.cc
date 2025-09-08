#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int c, n; cin >> c >> n;
	vector<pair<int, int>> v(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(c * 100));

	for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;

	for (int i = 1; i <= n; i++)
	{
		auto [cost, value] = v[i];
		for (int j = 1; j <= c * 100; j++)
		{
			if (cost > j)
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			dp[i][j] = max(dp[i - 1][j], dp[i][j - cost] + value);
		}
	}

	cout << (lower_bound(dp[n].begin(), dp[n].end(), c) - dp[n].begin());
}