#include <bits/stdc++.h>
using namespace std;

bool Check(vector<vector<int>> &v) {
    for (auto& i : v) {
        for (auto& j : i) {
            if (j > 0)return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int time = 0;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<bool>> ocean(n, vector<bool>(m));
    ocean[0][0] = true;
    while (Check(v)) {
        time++;

        vector<tuple<int, int, int>> ocean;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!v[i][j])continue;
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    int xx = j + offset[k][0];
                    int yy = i + offset[k][1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || v[yy][xx])continue;
                    sum++;
                }
                ocean.push_back({ i, j, sum });
            }
        }
        for (auto& i : ocean) {
            int x, y, cost; tie(y, x, cost) = i;
            v[y][x] = clamp(v[y][x] - cost, 0, 10);
        }

        vector<vector<bool>> visited(n, vector<bool>(m));
        int iceberg = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!v[i][j] || visited[i][j])continue;
                iceberg++;
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;
                while (!q.empty()) {
                    int x, y; tie(y, x) = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int xx = x + offset[k][0];
                        int yy = y + offset[k][1];
                        if (xx < 0 || xx >= m || yy < 0 || yy >= n)continue;
                        if (v[yy][xx] && !visited[yy][xx]) {
                            visited[yy][xx] = true;
                            q.push({ yy,xx });
                        }
                    }
                }
            }
        }
        if (iceberg > 1)break;
    }
    if (Check(v))cout << time;
    else cout << 0;
}
