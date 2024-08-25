#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    queue<pair<int, int>> bfs;
    bfs.push({ 0, 0 });
    maps[0][0] = 3;

    while (!bfs.empty()) {
        int y = bfs.front().first;
        int x = bfs.front().second;
        bfs.pop();
        if (y == n - 1 && x == m - 1)break;
        for (int i = 0; i < 4; i++) {
            int col = dy[i] + y;
            int row = dx[i] + x;
            if (col == -1 || row == -1 || col == n || row == m)continue;
            if (maps[col][row] != 1)continue;
            maps[col][row] = maps[y][x] + 1;
            bfs.push({ col, row });
        }
    }
    return maps[n - 1][m - 1] - 2;
}