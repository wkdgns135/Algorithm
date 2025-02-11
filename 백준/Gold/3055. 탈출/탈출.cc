#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int r, c; cin >> r >> c;
	vector<vector<char>> board(r, vector<char>(c));
	vector<vector<int>> depth(r, vector<int>(c, INT_MAX));
	queue<pair<int, int>> bfs;
	pair<int, int> start, end;
	int offset[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S')start = { i, j };
			if (board[i][j] == 'D')end = { i, j };
			if (board[i][j] == '*') {
				bfs.push({ i, j });
				depth[i][j] = 0;
			}
		}
	}

	while (!bfs.empty()) {
		int x, y; tie(y, x) = bfs.front();
		bfs.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + offset[i][0];
			int yy = y + offset[i][1];
			if (xx < 0 || xx >= c || yy < 0 || yy >= r)continue;
			if (board[yy][xx] == '.' && depth[yy][xx] > depth[y][x] + 1) {
				bfs.push({ yy,xx });
				depth[yy][xx] = depth[y][x] + 1;
			}
		}
	}

	vector<vector<int>> visited(r, vector<int>(c, INT_MAX));
	bfs.push(start);
	visited[start.first][start.second] = 0;
	while (!bfs.empty()) {
		int x, y; tie(y, x) = bfs.front();
		if (bfs.front() == end) {
			cout << visited[y][x];
			return 0;
		} 
		bfs.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + offset[i][0];
			int yy = y + offset[i][1];
			if (xx < 0 || xx >= c || yy < 0 || yy >= r || board[yy][xx] == 'X')continue;
			if (depth[yy][xx] > visited[y][x] + 1 && visited[yy][xx] > visited[y][x] + 1) {
				bfs.push({ yy,xx });
				visited[yy][xx] = visited[y][x] + 1;
			}
		}
	}

	cout << "KAKTUS";
}
