#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21, 1)));
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				if (i < j && j < k) dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
			}
		}
	}
	while (!(a == -1 && b == -1 && c == -1)) {
		cout<< "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0)cout << 1 << '\n';
		else if(a > 20 || b > 20 || c > 20)cout << dp[20][20][20] << '\n';
		else cout << dp[a][b][c] << '\n';
		cin >> a >> b >> c;
	}
}