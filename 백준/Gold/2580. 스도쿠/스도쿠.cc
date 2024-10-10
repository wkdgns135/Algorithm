#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(9, vector<int>(9));
vector<pair<int, int>> emptyNums;

bool CheckNum(int n, int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (v[y][i] == n) return false;
        if (v[i][x] == n) return false;
    }
    int xx = x / 3 * 3, yy = y / 3 * 3;
    for (int i = yy; i < yy + 3; i++) {
        for (int j = xx; j < xx + 3; j++) {
            if (v[i][j] == n) return false;
        }
    }
    return true;
}

bool BackTracking(int depth) {
    if (depth == emptyNums.size()) return true;

    for (int i = 1; i <= 9; i++) {
        int x = emptyNums[depth].second;
        int y = emptyNums[depth].first;

        if (!CheckNum(i, x, y)) continue;

        v[y][x] = i;
        if (BackTracking(depth + 1)) return true;

        v[y][x] = 0;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
        cin >> v[i][j];
        if (v[i][j] == 0) emptyNums.push_back({ i, j });
    }

    BackTracking(0);

    for (auto& i : v) {
        for (auto& j : i) cout << j << ' ';
        cout << '\n';
    }
}
