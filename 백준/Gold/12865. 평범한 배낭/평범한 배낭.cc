#include <vector>
#include <iostream>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));

	for (int i = 1; i <= n; i++)
	{
		int w, v; cin >> w >> v;

		for (int j = 1; j <= k; j++)
		{
			if (w > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
		}
	}

	cout << dp[n][k];
}
