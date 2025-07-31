#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<vector<int>> v(n), dp(n);

	for (int i = 0; i < n; i++)
	{
		v[i].resize(i + 1);
		dp[i].resize(i + 1);
		for (int j = 0; j <= i; j++)
		{
			cin >> v[i][j];
		}
	}

	dp[0][0] = v[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == i) dp[i][j] = dp[i - 1][j - 1] + v[i][j];
			else if (j == 0) dp[i][j] = dp[i - 1][j] + v[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
		}
	}
	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
}