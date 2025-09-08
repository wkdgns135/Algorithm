#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int c, n; cin >> c >> n;
	vector<int> dp(c + 101, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int cost, value; cin >> cost >> value;
		for (int j = value; j <= c + 100; j++)
		{
			if (dp[j - value] == INT_MAX) continue;
			dp[j] = min(dp[j], dp[j - value] + cost);
		}
	}
	cout << *min_element(dp.begin() + c, dp.begin() + c + 100);
}