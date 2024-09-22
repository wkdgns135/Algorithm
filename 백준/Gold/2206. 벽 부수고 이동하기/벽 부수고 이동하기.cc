#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<string> v(n);
    vector<vector<vector<int>>> mdt(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
    mdt[0][0][0] = 1;

    for (int i = 0; i < n; i++) cin >> v[i];

    int answer = INT_MAX;
    queue<pair<pair<int, int>, bool>> bfs;
    bfs.push({{ 0, 0 }, false});
    while (!bfs.empty()) {
        int x = bfs.front().first.second;
        int y = bfs.front().first.first;
        bool z = bfs.front().second;
        if (x == m - 1 && y == n - 1) {
            answer = mdt[y][x][z];
            break;
        }
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            
            if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
                if (v[yy][xx] == '1' && !z && mdt[yy][xx][true] == INT_MAX) {
                    mdt[yy][xx][true] = mdt[y][x][z] + 1;
                    bfs.push({ {yy,xx}, true });
                }
                if (v[yy][xx] == '0' && mdt[yy][xx][z] == INT_MAX) {
                    mdt[yy][xx][z] = mdt[y][x][z] + 1;
                    bfs.push({ {yy,xx}, z });
                }
            }
        }
    }
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}