#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
void DivideConquer(int n, int x, int y) {
    if (n == 1) {
        v[y][x] = '*';
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (i == 4)continue;
        int xx = (i * n / 3) % n;
        int yy = (i * n / 3) / n * n / 3;
        DivideConquer(n / 3, x + xx, y + yy);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    v = vector<vector<char>>(n, vector<char>(n, ' '));
    DivideConquer(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << v[i][j];
        cout << '\n';
    }
}