#include <bits/stdc++.h>
using namespace std;

struct Eye {
    int top, bottom, left, right, front, back;
};

class Dice {
    int x, y;
    Eye eye;
public:
    Dice(int x, int y) {
        this->x = x;
        this->y = y;
        eye = { 0,0,0,0,0,0 };
    }
    void MoveEast() {
        Eye temp = eye;
        eye.top = temp.left;
        eye.bottom = temp.right;
        eye.left = temp.bottom;
        eye.right = temp.top;
    }
    void MoveWest() {
        Eye temp = eye;
        eye.top = temp.right;
        eye.bottom = temp.left;
        eye.left = temp.top;
        eye.right = temp.bottom;
    }
    void MoveNorth() {
        Eye temp = eye;
        eye.top = temp.front;
        eye.bottom = temp.back;
        eye.front = temp.bottom;
        eye.back = temp.top;
    }
    void MoveSouth() {
        Eye temp = eye;
        eye.top = temp.back;
        eye.bottom = temp.front;
        eye.front = temp.top;
        eye.back = temp.bottom;
    }
    inline void SetBottom(int num) {eye.bottom = num; }
    inline void SetX(int x) { this->x = x; }
    inline void SetY(int y) { this->y = y; }
    inline int GetBottom() { return eye.bottom; }
    inline int GetTop() { return eye.top; }
    inline int GetX() { return x; }
    inline int GetY() { return y; }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, k; cin >> n >> m >> y >> x >> k;
    int offset[4][2] = { {0, 1},{0, -1}, {-1,0},{1,0} };
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) cin >> v[i][j];
    
    Dice dice(x, y);
    while (k--) {
        int input; cin >> input;
        int xx = dice.GetX() + offset[input - 1][1];
        int yy = dice.GetY() + offset[input - 1][0];
        if (xx < 0 || xx >= m || yy < 0 || yy >= n)continue;
        if (input == 1)dice.MoveEast();
        if (input == 2)dice.MoveWest();
        if (input == 3)dice.MoveNorth();
        if (input == 4)dice.MoveSouth();
        cout << dice.GetTop() << '\n';
        if (v[yy][xx] == 0)v[yy][xx] = dice.GetBottom();
        else {
            dice.SetBottom(v[yy][xx]);
            v[yy][xx] = 0;
        }
        dice.SetX(xx);
        dice.SetY(yy);
    }
}
