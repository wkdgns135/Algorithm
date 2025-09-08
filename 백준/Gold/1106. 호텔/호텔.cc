#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int c, n; cin >> c >> n;
	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
	vector<int> dp(c * 100 + 1);

	for (int i = 1; i <= n; i++)
	{
		auto [cost, value] = v[i];
		for (int j = cost; j <= c * 100; j++)
		{
			dp[j] = max(dp[j], dp[j - cost] + value);
		}
	}
	cout << lower_bound(dp.begin(), dp.end(), c) - dp.begin();
}