#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    while (t--) {
        int m, n, k; cin >> m >> n >> k;
        vector<vector<int>> v(n, vector<int>(m));
        vector<pair<int, int>> pos;
        while (k--) {
            int x, y; cin >> x >> y;
            pos.push_back({ x, y });
            v[y][x] = 1;
        }
        int count = 0;
        for (int i = 0; i < pos.size(); i++) {
            if (!v[pos[i].second][pos[i].first])continue;
            v[pos[i].second][pos[i].first] = 0;
            queue<pair<int, int>> bfs;
            bfs.push({ pos[i].first, pos[i].second });
            count++;
            while (!bfs.empty()) {
                int x = bfs.front().first;
                int y = bfs.front().second;
                bfs.pop();

                for (int j = 0; j < 4; j++) {
                    int xx = x + offset[j][0];
                    int yy = y + offset[j][1];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && v[yy][xx]) {
                        v[yy][xx] = 0;
                        bfs.push({ xx, yy });
                    }
                }
            }
        }
        cout << count << '\n';
    }
}