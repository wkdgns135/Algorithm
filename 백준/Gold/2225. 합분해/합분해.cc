#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<vector<int>> dp(k + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 1000000000;
			}
		}
	}
	cout << dp[k][n];
}
