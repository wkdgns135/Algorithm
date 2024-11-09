#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    queue<pair<int, int>> bfs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'I')bfs.push({ i , j });
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[bfs.front().first][bfs.front().second] = true;
    int offset[4][2] = { {1, 0}, {-1,0},{0,1},{0, -1} };
    int answer = 0;
    while (!bfs.empty()) {
        pair<int, int> pos = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int x = pos.second + offset[i][0];
            int y = pos.first + offset[i][1];

            if (x < 0 || x >= m || y < 0 || y >= n || visited[y][x] || v[y][x] == 'X')continue;
            visited[y][x] = true;
            bfs.push({ y,x });
            answer += v[y][x] == 'P';
        }
    }
    if (answer == 0)cout << "TT";
    else cout << answer;
}
