#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> board) {
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'R') {
                queue<pair<pair<int, int>, int>> bfs;
                bfs.push({ { i, j }, 0 });
                visited[i][j] = true;
                while (!bfs.empty()) {
                    int x = bfs.front().first.second;
                    int y = bfs.front().first.first;
                    int count = bfs.front().second;
                    bfs.pop();
                    if (board[y][x] == 'G')return count;
                    for (int k = 0; k < 4; k++) {
                        int xx = x;
                        int yy = y;
                        while (xx < board[i].size() && xx >= 0 && yy < board.size() && yy >= 0) {
                            if (board[yy][xx] == 'D')break;
                            xx += offset[k][1];
                            yy += offset[k][0];
                        }
                        xx -= offset[k][1];
                        yy -= offset[k][0];
                        if (visited[yy][xx])continue;
                        visited[yy][xx] = true;
                        bfs.push({ { yy, xx }, count + 1 });

                    }
                }
                break;
            }
        }
    }
    return -1;
}