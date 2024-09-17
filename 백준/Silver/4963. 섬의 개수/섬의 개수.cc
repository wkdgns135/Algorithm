#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int offset[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1, -1},{-1,1} };

    int w, h; cin >> w >> h;
    do {
        int answer = 0;
        vector<vector<int>> v(h, vector<int>(w));
        for (int i = 0; i < h; i++)for (int j = 0; j < w; j++) cin >> v[i][j];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!v[i][j])continue;
                answer++;
                queue<pair<int, int>> dfs;
                dfs.push({ i, j });
                v[i][j] = 0;
                while (!dfs.empty()) {
                    auto pos = dfs.front();
                    dfs.pop();
                    for (int k = 0; k < 8; k++) {
                        int x = pos.second + offset[k][0];
                        int y = pos.first + offset[k][1];
                        if (x >= 0 && x < w && y >= 0 && y < h && v[y][x]) {
                            v[y][x] = 0;
                            dfs.push({ y,x });
                        }
                    }
                }
            }
        }
        cout << answer << '\n';
        cin >> w >> h;
    } while (w * h != 0);
}