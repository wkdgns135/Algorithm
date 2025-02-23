#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	vector<vector<long long>> dp(100001, vector<long long>(3));
	dp[1][0] = 1, dp[2][1] = 1, dp[3][2] = 1;
	for (int i = 3; i < 100001; i++)
	{
		dp[i][0] += (dp[i - 1][1] + dp[i - 1][2]) % 1000000009;
		dp[i][1] += (dp[i - 2][0] + dp[i - 2][2]) % 1000000009;
		dp[i][2] += (dp[i - 3][0] + dp[i - 3][1]) % 1000000009;
	}
	while (t--)
	{
		int n; cin >> n;
		cout << accumulate(dp[n].begin(), dp[n].end(), (long long)0) % 1000000009 << '\n';
	}
}
