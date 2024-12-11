#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int r, c, t; cin >> r >> c >> t;
	vector<vector<int>> v(r, vector<int>(c)), temp(r, vector<int>(c));
	pair<int, int> top, bottom;
	int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
			if (v[i][j] == -1 && bottom == pair<int, int>(0, 0)) {
				top = { i, j };
				bottom = { i + 1, j };
			}
		}
	}

	while (t--) {
		queue<pair<int, int>> dust;
		temp.assign(r, vector<int>(c, 0));

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (v[i][j] > 0)dust.push({ i, j });
			}
		}
		while (!dust.empty()) {
			int y, x; tie(y, x) = dust.front();
			dust.pop();
			int spread = 0;
			for (int i = 0; i < 4; i++) {
				int xx = x + offset[i][0];
				int yy = y + offset[i][1];

				if (xx >= 0 && xx < c && yy >= 0 && yy < r && v[yy][xx] != -1) {
					spread++;
					temp[yy][xx] += v[y][x] / 5;
				}
			}
			v[y][x] -= v[y][x] / 5 * spread;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (temp[i][j] > 0) v[i][j] += temp[i][j];
			}
		}
		v[top.first - 1][0] = 0;
		for (int i = top.first - 1; i > 0; i--) {
			v[i][0] = v[i - 1][0];
		}
		for (int i = 0; i < c - 1; i++) {
			v[0][i] = v[0][i + 1];
		}
		for (int i = 0; i < top.first; i++) {
			v[i][c - 1] = v[i + 1][c - 1];
		}
		for (int i = c - 1; i > 1; i--) {
			v[top.first][i] = v[top.first][i - 1];
		}
		v[top.first][1] = 0;

		v[bottom.first + 1][0] = 0;
		for (int i = bottom.first + 1; i < r - 1; i++) {
			v[i][0] = v[i + 1][0];
		}
		for (int i = 0; i < c - 1; i++) {
			v[r - 1][i] = v[r - 1][i + 1];
		}
		for (int i = r - 1; i > bottom.first; i--) {
			v[i][c - 1] = v[i - 1][c - 1];
		}
		for (int i = c - 1; i > 1; i--) {
			v[bottom.first][i] = v[bottom.first][i - 1];
		}
		v[bottom.first][1] = 0;
	}
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] > 0)result += v[i][j];
		}
	}
	cout << result << '\n';
}