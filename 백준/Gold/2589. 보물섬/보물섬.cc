#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> board;
int offset[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int BFS(pair<int, int> start) {
	int result = 0;
	vector<vector<int>> depth(n, vector<int>(m, -1));
	queue<pair<int, int>> bfs;
	bfs.push(start);
	depth[start.first][start.second] = 0;
	while (!bfs.empty()) {
		int x, y; tie(y, x) = bfs.front();
		bfs.pop();

		if (result < depth[y][x]) {
			result = depth[y][x];
		}

		for (int i = 0; i < 4; i++) {
			int xx = x + offset[i][0];
			int yy = y + offset[i][1];
			if (xx < 0 || xx >= m || yy < 0 || yy >= n)continue;
			if (depth[yy][xx] == -1 && board[yy][xx] == 'L') {
				bfs.push({ yy, xx });
				depth[yy][xx] = depth[y][x] + 1;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	board.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'W')continue;
			int result = BFS({ i, j });
			answer = max(answer, result);
		}
	}
	cout << answer;
}
