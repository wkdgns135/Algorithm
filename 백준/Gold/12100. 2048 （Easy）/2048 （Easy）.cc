#include <bits/stdc++.h>
using namespace std;

int n, answer = 0;
vector<vector<int>> Simulation(vector<vector<int>> v, int dir) {
    vector<vector<bool>> merged(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x, y, xx, yy; x = y = xx = yy = 0;
            if (dir == 0 || dir == 1)x = j, y = i;
            if (dir == 2)x = n - j - 1, y = i;
            if (dir == 3)x = j, y = n - i - 1;
            if (!v[y][x])continue;

            xx = x, yy = y;
            int num = v[y][x];
            v[y][x] = 0;

            if (dir == 0) for (xx; xx > 0 && !v[y][xx]; xx--);
            if (dir == 1) for (yy; yy > 0 && !v[yy][x]; yy--);
            if (dir == 2) for (xx; xx < n - 1 && !v[y][xx]; xx++);
            if (dir == 3) for (yy; yy < n - 1 && !v[yy][x]; yy++);

            if (y == yy && x == xx) {
                v[y][x] = num;
                continue;
            }

            if (!v[yy][xx]) {
                v[yy][xx] = num;
            }
            else if(v[yy][xx] == num && !merged[yy][xx]) {
                merged[yy][xx] = true;
                v[yy][xx] *= 2;
            }
            else {
                if (dir == 0)v[yy][xx + 1] = num;
                if (dir == 1)v[yy + 1][xx] = num;
                if (dir == 2)v[yy][xx - 1] = num;
                if (dir == 3)v[yy - 1][xx] = num;
            }
        }
    }

    return v;
}

void BackTracking(int depth, vector<vector<int>> v) {
    if (depth == 5) {
        int maxVal = 0;
        for (auto& y : v) for (auto& x : y)maxVal = max(maxVal, x);
        answer = max(answer, maxVal);
        return;
    }
    for (int i = 0; i < 4; i++) {
        BackTracking(depth + 1, Simulation(v, i));
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    BackTracking(0, v);
    cout << answer;
}
