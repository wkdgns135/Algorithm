#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    queue<pair<int, int>> bfs;
    int offset[4][2] = { { 0,-1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
        { 
            cin >> v[i][j]; 
            if (v[i][j] == 1) v[i][j] = -1;
            if (v[i][j] == 2) { bfs.push({ i ,j }); v[i][j] = 0; }
        }
    
    while (!bfs.empty()) {
        int x = bfs.front().second;
        int y = bfs.front().first;
        int depth = v[y][x];
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            if (yy < 0 || yy >= N || xx < 0 || xx >= M || v[yy][xx] != -1)continue;
            v[yy][xx] = depth + 1;
            bfs.push({yy, xx});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)cout << v[i][j] << ' ';
        cout << "\n";
    }
    return 0;
}