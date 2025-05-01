#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int H, Y;
	cin >> H >> Y;

	int dp[11]; // 최대 10년
	dp[0] = H;

	for (int i = 1; i <= Y; ++i)
	{
		dp[i] = dp[i - 1] * 105 / 100; // A 방식
		if (i >= 3)
		{
			dp[i] = max(dp[i], dp[i - 3] * 120 / 100); // B 방식
		}
		if (i >= 5)
		{
			dp[i] = max(dp[i], dp[i - 5] * 135 / 100); // C 방식
		}
	}

	cout << dp[Y] << '\n';
}
