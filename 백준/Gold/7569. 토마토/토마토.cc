#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, n, h; cin >> m >> n >> h;

    vector<vector<vector<int>>> v(h, vector<vector<int>>(n, vector<int>(m)));
    vector<vector<int>> pos;
    int offset[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0}, {1,0,0},{-1,0,0} };
    for (int i = 0; i < h; i++)for (int j = 0; j < n; j++)for (int k = 0; k < m; k++) { cin >> v[i][j][k]; if (v[i][j][k] == 1)pos.push_back({i, j, k}); }

    queue<vector<vector<int>>> bfs;
    bfs.push(pos);

    while (!bfs.empty()) {
        vector<vector<int>> now = bfs.front();
        bfs.pop();
        vector<vector<int>> next;
        for (int i = 0; i < now.size(); i++) {
            int x = now[i][2];
            int y = now[i][1];
            int z = now[i][0];

            for (int j = 0; j < 6; j++) {
                int xx = x + offset[j][2];
                int yy = y + offset[j][1];
                int zz = z + offset[j][0];

                if (xx >= 0 && x < m && yy >= 0 && yy < n && zz >= 0 && zz < h && !v[zz][yy][xx]) {
                    v[zz][yy][xx] = v[z][y][x] + 1;
                    next.push_back({zz, yy, xx });
                }
            }
        }
        if (!next.empty())bfs.push(next);
    }
    int max = -INT_MAX;
    for (int i = 0; i < h; i++)for (int j = 0; j < n; j++)for (int k = 0; k < m; k++) {
        if (v[i][j][k] == 0) {
            cout << -1;
            return 0;
        }
        max = std::max(max, v[i][j][k]);
    }
    cout << max - 1 ;
}
