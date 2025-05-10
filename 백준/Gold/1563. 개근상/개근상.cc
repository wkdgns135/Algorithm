#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(3)));
	dp[0][0] = { 1,1,0 };
	dp[1][0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[0][i][0] = dp[0][i - 1][0] + dp[0][i - 1][1] + dp[0][i - 1][2];
		dp[0][i][1] = dp[0][i - 1][0];
		dp[0][i][2] = dp[0][i - 1][1];

		dp[1][i][0] = dp[0][i][0] + dp[1][i - 1][0] + dp[1][i - 1][1] + dp[1][i - 1][2];
		dp[1][i][1] = dp[1][i - 1][0];
		dp[1][i][2] = dp[1][i - 1][1];

		for (int j = 0; j < 3; j++)
		{
			dp[0][i][j] %= 1000000;
			dp[1][i][j] %= 1000000;
		}
	}

	int answer = 0;

	for (int j = 0; j < 3; j++)
	{

		answer += dp[0][n - 1][j] + dp[1][n - 1][j];
		answer %= 1000000;
	}

	cout << answer;
}