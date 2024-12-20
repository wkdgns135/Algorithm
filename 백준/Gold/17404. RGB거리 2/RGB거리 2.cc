#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(3));
	for (int i = 0; i < n; i++)cin >> v[i][0] >> v[i][1] >> v[i][2];
	vector<vector<vector<int>>> dp(3, vector<vector<int>>(n, vector<int>(3)));
	int answer = INT_MAX;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)continue;
			dp[i][0][j] = 9999;
		}
		dp[i][0][i] = v[0][i];
		for (int j = 1; j < n; j++) {
			dp[i][j][0] = min(dp[i][j - 1][1], dp[i][j - 1][2]) + v[j][0];
			dp[i][j][1] = min(dp[i][j - 1][0], dp[i][j - 1][2]) + v[j][1];
			dp[i][j][2] = min(dp[i][j - 1][0], dp[i][j - 1][1]) + v[j][2];
		}
		for (int j = 0; j < 3; j++) {
			if (i == j)continue;
			answer = min(answer, dp[i][n - 1][j]);
		}
	}
	cout << answer;
}