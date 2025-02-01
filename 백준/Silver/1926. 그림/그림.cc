#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<bool>> visited(n, vector<bool>(m));
	int cnt = 0, maxArea = 0;
	int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || !v[i][j])continue;
			cnt++;
			int area = 1;

			queue<pair<int, int>> bfs;
			bfs.push({ i, j });
			visited[i][j] = true;

			while (!bfs.empty()) {
				int x, y; tie(y, x) = bfs.front();
				bfs.pop();
				for (int k = 0; k < 4; k++) {
					int xx = x + offset[k][0];
					int yy = y + offset[k][1];
					if (xx < 0 || xx >= m || yy < 0 || yy >= n)continue;
					if (visited[yy][xx] || !v[yy][xx])continue;
					bfs.push({ yy, xx });
					visited[yy][xx] = true;
					area++;
				}
			}
			maxArea = max(maxArea, area);
		}
	}
	cout << cnt << '\n' << maxArea;
}
