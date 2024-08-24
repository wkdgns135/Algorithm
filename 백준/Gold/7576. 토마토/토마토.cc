#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, n; cin >> m >> n;

    vector<vector<int>> v(n, vector<int>(m));
    vector<pair<int,int>> pos;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) { cin >> v[i][j]; if (v[i][j] == 1)pos.push_back({ i,j }); }

    queue<vector<pair<int, int>>> bfs;
    bfs.push(pos);

    while (!bfs.empty()) {
        vector<pair<int, int>> now = bfs.front();
        bfs.pop();
        vector<pair<int, int>> next;
        for (int i = 0; i < now.size(); i++) {
            int x = now[i].second;
            int y = now[i].first;
            for (int j = 0; j < 4; j++) {
                int xx = x + offset[j][0];
                int yy = y + offset[j][1];
                if (xx >= 0 && x < m && yy >= 0 && yy < n && !v[yy][xx]) {
                    v[yy][xx] = v[y][x] + 1;
                    next.push_back({ yy, xx });
                }
            }
        }
        if (!next.empty())bfs.push(next);
    }
    int max = -INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                cout << -1;
                return 0;
            }
            max = std::max(max, v[i][j]);
        }
    }
    cout << max - 1 ;
}
