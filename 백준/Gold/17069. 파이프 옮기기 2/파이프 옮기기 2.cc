#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(n, vector<long long>(n)));
	for (int i = 1; i < n; i++) {
		if (v[0][i])break;
		dp[0][0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (v[i][j])continue;
			dp[0][i][j] += dp[0][i][j - 1] + dp[1][i][j - 1];
			if(!v[i - 1][j] && !v[i][j - 1]) dp[1][i][j] += dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			dp[2][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];
		}
	}
	cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1];
}