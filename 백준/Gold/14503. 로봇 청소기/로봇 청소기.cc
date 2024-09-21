#include <bits/stdc++.h>
using namespace std;

bool CheckNeighbor(vector<vector<int>> &v, int x, int y) {
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    for (int i = 0; i < 4; i++) {
        int xx = x + offset[i][0];
        int yy = y + offset[i][1];
        if (v[yy][xx] == 0)return true;
    }
    return false;
}

pair<int, int> FrontPos(vector<vector<int>>& v, int x, int y, int d) {
    if (d == 0)return { y - 1, x };
    if (d == 1)return { y, x + 1 };
    if (d == 2)return { y + 1, x };
    if (d == 3)return { y, x - 1 };
}

pair<int, int> BackPos(vector<vector<int>>& v, int x, int y, int d) {
    if (d == 0)return { y + 1, x };
    if (d == 1)return { y, x - 1 };
    if (d == 2)return { y - 1, x };
    if (d == 3)return { y, x + 1 };
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2));
    int r, c, d; cin >> r >> c >> d;

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) v[i][j] = 1;
            else cin >> v[i][j];
        }
    }

    pair<int, int> curPos = { r + 1, c + 1 };
    v[r + 1][c + 1] = 2;
    int answer = 1;

    while (v[curPos.first][curPos.second] != 1) {
        int x = curPos.second;
        int y = curPos.first;

        if (!CheckNeighbor(v, x, y)) {
            auto pos = BackPos(v, x, y, d);
            curPos = pos;
        }
        else {
            d = ((d - 1) % 4 + 4) % 4;
            auto pos = FrontPos(v, x, y, d);
            if (v[pos.first][pos.second] != 0) continue;
            v[pos.first][pos.second] = 2;
            answer++;
            curPos = pos;
        }
    }
    cout << answer;
}