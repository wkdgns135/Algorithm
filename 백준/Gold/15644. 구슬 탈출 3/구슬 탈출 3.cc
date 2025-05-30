#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int y, x;
    bool operator == (const Pos & a) {
        return a.x == x && y == a.y;
    }
};

int n, m;
bool MoveBall(Pos &pos, vector<vector<char>> &board, int d) {
    int offset[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    int x = pos.x + offset[d][1], y = pos.y + offset[d][0];
    while (x >= 0 && x < m && y >= 0 && y < n && (board[y][x] == '.' || board[y][x] == 'O')) {
        if (board[y][x] == 'O')return true;
        pos.x = x, pos.y = y;
        x += offset[d][1], y += offset[d][0];
    }
    return false;
}

pair<bool, bool> RotateBoard(Pos &red, Pos &blue, int i, vector<vector<char>>& board) {
    bool bRed = false, bBlue = false;
    if (i == 0 || i == 1) {
        if (red.x > blue.x || red.y > blue.y) {
            board[red.y][red.x] = '.';
            bRed = MoveBall(red, board, i);
            if (bRed)board[red.y][red.x] = '.';
            else board[red.y][red.x] = 'R';
            bBlue = MoveBall(blue, board, i);
        }
        else {
            board[blue.y][blue.x] = '.';
            bBlue = MoveBall(blue, board, i);
            board[blue.y][blue.x] = 'B';
            bRed = MoveBall(red, board, i);
        }
    }
    else {
        if (red.x > blue.x || red.y > blue.y) {
            board[blue.y][blue.x] = '.';
            bBlue = MoveBall(blue, board, i);
            board[blue.y][blue.x] = 'B';
            bRed = MoveBall(red, board, i);
        }
        else {
            board[red.y][red.x] = '.';
            bRed = MoveBall(red, board, i);
            if(bRed)board[red.y][red.x] = '.';
            else board[red.y][red.x] = 'R';
            bBlue = MoveBall(blue, board, i);
        }
    }
    board[red.y][red.x] = '.';
    board[blue.y][blue.x] = '.';
    return { bRed , bBlue };
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    Pos startRed, startBlue;
    unordered_map<int, char> dict = { {0, 'R'}, {1, 'D'}, {2, 'L'}, {3, 'U'} };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                startRed = { i, j };
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                startBlue = { i, j };
                board[i][j] = '.';
            }
        }
    }

    queue<tuple<vector<int>, Pos, Pos>> bfs;
    bfs.push({ {}, startRed, startBlue });

    while (!bfs.empty()) {
        vector<int> depth;
        Pos red, blue; 
        tie(depth, red, blue) = bfs.front();
        bfs.pop();
        if (depth.size() == 10)break;
        for (int i = 0; i < 4; i++) {
            Pos newRed = red, newBlue = blue;
            bool bRed, bBlue; tie(bRed, bBlue) = RotateBoard(newRed, newBlue, i, board);
            if (bRed && !bBlue) {
                cout << depth.size() + 1 << '\n';
                for (int& j : depth)cout << dict[j];
                cout << dict[i];
                return 0;
            }
            if (newRed == red && newBlue == blue)continue;
            if (bBlue || bRed)continue;
            vector<int> temp = depth;
            temp.push_back(i);
            bfs.push({ temp, newRed, newBlue });
        }
    }
    cout << -1 << '\n';
}
