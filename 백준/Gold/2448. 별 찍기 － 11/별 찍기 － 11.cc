#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> v;

void triangle(int x, int y, bool z) {
    v[y][x] = z;
    v[y + 1][x - 1] = z;
    v[y + 1][x + 1] = z;
    for (int i = 0; i < 5; i++) {
        v[y + 2][x - 2 + i] = z;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    v.resize(n, vector<bool>(n * 2));

    queue<pair<int, int>> q;
    q.push({ n, 0 });

    for (int depth = 0; depth < n; depth += 3) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();
            if (y > 0 && x > 0 && v[y - 1][x + 1] && v[y - 1][x - 1])continue;
            triangle(x, y, true);
            q.push({ x - 3, y + 3 });
            q.push({ x + 3, y + 3 });
            
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 1; x < n * 2; x++) {
            cout << (v[y][x] ? '*' : ' ');
        }
        cout << '\n';
    }
}
