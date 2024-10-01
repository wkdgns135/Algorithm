#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int y;
    int x;
    Pos operator +(Pos &b) {
        return {y + b.y, x + b.x};
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, l; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    unordered_map<int, char> rotations;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> y >> x;
        v[y - 1][x - 1] = 2;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int x; char c; cin >> x >> c;
        rotations[x] = c;
    }
    deque<Pos> snake;
    snake.push_back({ 0, 0 });
    v[0][0] = 1;

    vector<Pos> offset = { {0,1},{1,0},{0,-1},{-1,0} };
    int direction = 0;
    int time = 0;
    while (true) {
        time++;
        auto head = snake.front();
        auto tail = snake.back();
        auto next = head + offset[direction];
        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n || v[next.y][next.x] == 1)break;
        snake.push_front(next);
        if (v[next.y][next.x] == 0) {
            v[tail.y][tail.x] = 0;
            snake.pop_back();
        }
        v[next.y][next.x] = 1;
        if (rotations[time] == 'L')direction = ((direction - 1) + 4) % 4;
        if (rotations[time] == 'D')direction = (direction + 1) % 4;
    }
    cout << time;
}
