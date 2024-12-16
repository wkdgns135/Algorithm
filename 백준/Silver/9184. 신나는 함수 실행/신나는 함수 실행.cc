#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, 1)));
	for (int i = 51; i <= 70; i++) {
		for (int j = 51; j <= 70; j++) {
			for (int k = 51; k <= 70; k++) {
				if (i < j && j < k) dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
			}
		}
	}
	while (!(a == -1 && b == -1 && c == -1)) {
		cout<< "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0)cout << 1 << '\n';
		else if(a > 20 || b > 20 || c > 20)cout << dp[70][70][70] << '\n';
		else cout << dp[a + 50][b + 50][c + 50] << '\n';
		cin >> a >> b >> c;
	}
}