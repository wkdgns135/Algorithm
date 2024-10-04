#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v;
vector<int> result(3, 0);

int CheckArea(int x, int y, int size) {
    int pre = v[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (v[i][j] != pre)return -1;
            pre = v[i][j];
        }
    }
    return pre + 1;
}

void DivideConquer(int x, int y, int size) {
    if (size == 1) {
        result[v[y][x] + 1]++;
        return;
    }

    int check = CheckArea(x, y, size);
    if (check != -1) {
        result[check]++;
        return;
    }

    for (int i = 0; i < size; i += size / 3) {
        for (int j = 0; j < size; j += size / 3) {
            DivideConquer(x + j, y + i, size / 3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    DivideConquer(0, 0, n);
    for (auto& i : result)cout << i << '\n';
}
