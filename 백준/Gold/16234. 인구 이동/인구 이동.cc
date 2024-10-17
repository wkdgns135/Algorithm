#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l, r; cin >> n >> l >> r;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> v[i][j];
    
    vector<vector<pair<int, int>>> groups;
    int answer = 0;
    do {
        groups.clear();
        vector<vector<bool>> visited(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j])continue;
                stack<pair<int, int>> dfs;
                vector<pair<int, int>> group;
                group.push_back({ i, j });
                dfs.push({ i, j });
                visited[i][j] = true;
                while (!dfs.empty()) {
                    int x, y; tie(y, x) = dfs.top();
                    dfs.pop();
                    for (int k = 0; k < 4; k++) {
                        int xx = x + offset[k][0];
                        int yy = y + offset[k][1];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= n || visited[yy][xx])continue;
                        int diff = abs(v[y][x] - v[yy][xx]);
                        if (diff >= l && diff <= r) {
                            visited[yy][xx] = true;
                            dfs.push({ yy,xx });
                            group.push_back({ yy, xx });
                        }
                   }
                }
                if(group.size() > 1)groups.push_back(group);
            }
        }
        for (auto& group : groups) {
            int sum = 0;
            for (auto& pos : group) sum += v[pos.first][pos.second];
            for (auto& pos : group) v[pos.first][pos.second] = sum / group.size();
        }
        answer += !groups.empty();
    } while (!groups.empty());

    cout << answer;
}
