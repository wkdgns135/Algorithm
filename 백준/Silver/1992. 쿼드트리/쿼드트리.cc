#include <bits/stdc++.h>
using namespace std;

vector<string> v;
bool CheckQuad(int size, int x, int y) {
    int sum = 0;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            sum += v[i][j] - '0';
        }
    }
    if (!sum || sum == size * size)return true;
    return false;
}
void DivideConquer(int size, int x, int y) {
    if (CheckQuad(size, x, y)) {
        cout << v[y][x];
        return;
    }

    cout << '(';
    for (int i = 0; i < 4; i++) {
        int xx = x + (i % 2) * (size / 2);
        int yy = y + (i / 2) * (size / 2);
        DivideConquer(size / 2, xx, yy);
    }
    cout << ')';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    v = vector<string>(n); for (int i = 0; i < n; i++) cin >> v[i];
    DivideConquer(n, 0, 0);
}