#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<vector<bool>> v(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input; cin >> input;
			v[i][j] = input;
		}
	}
	int offset[3][3][2] = { { {0,1},{1,1},{0,0} },{ {0,1},{1,1},{1,0} },{{0,0},{1,1},{1,0}} };
	// type 0: {0,1}, {1,1}
	// type 1: {0,1}, {1,1}, {1,0}
	// type 2: {1,0}, {1,1}
	vector<vector<int>> dp(n, vector<int>(n));
	queue<tuple<int, int, int>> bfs;
	dp[0][1] = 1;
	bfs.push({ 0, 1, 0});
	while (!bfs.empty()) {
		int x, y, type; tie(y, x, type) = bfs.front();
		bfs.pop();
		for (int i = 0; i < 3; i++) {
			int xx = x + offset[type][i][1];
			int yy = y + offset[type][i][0];
			if (xx == x && yy == y)continue;
			if (xx < 0 || xx >= n || yy < 0 || yy >= n || v[yy][xx])continue;
			if (i == 1 && (v[yy][xx - 1] || v[yy - 1][xx]))continue;
			dp[yy][xx]++;
			bfs.push({ yy, xx, i });
		}
	}
	cout << dp[n - 1][n - 1];
}