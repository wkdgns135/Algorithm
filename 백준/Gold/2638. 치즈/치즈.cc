#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2));
    vector<vector<bool>> air(n + 2, vector<bool>(m + 2));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i + 1][j + 1];
        }
    }

    for (int i = 0; i < n + 2; i++) {
        air[i][0] = true;
        air[i][m + 1] = true;
    }
    for (int i = 0; i < m + 2; i++) {
        air[0][i] = true;
        air[n + 1][i] = true;
    }

    int time = 0, cnt = 1;
    int offset[4][2] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };
    while (cnt) {
        time++;
        cnt = 0;

        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                if (air[i][j] || v[i][j])continue;
                queue<pair<int, int>> bfs;
                bfs.push({ i, j });
                vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
                visited[i][j] = true;
                while (!bfs.empty()) {
                    int y, x; tie(y, x) = bfs.front();
                    bfs.pop();
                    if (air[y][x]) {
                        air[i][j] = true;
                        break;
                    }
                    for (int k = 0; k < 4; k++) {
                        int xx = offset[k][0] + x;
                        int yy = offset[k][1] + y;
                        if (visited[yy][xx] || v[yy][xx])continue;
                        bfs.push({ yy, xx });
                        visited[yy][xx] = true;
                    }
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (!v[i][j])continue;
                int airCnt = 0;
                for (int k = 0; k < 4; k++) {
                    int xx = offset[k][0] + j;
                    int yy = offset[k][1] + i;
                    if (air[yy][xx])airCnt++;
                }
                if (airCnt > 1) {
                    v[i][j] = 0;
                }
                cnt += v[i][j];
            }
        }
    }

    cout << time << '\n';
}