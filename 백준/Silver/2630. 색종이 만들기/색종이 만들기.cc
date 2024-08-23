#include <bits/stdc++.h>
using namespace std;

int zero = 0, one = 0;
void compress(vector<vector<int>> &v, int size, int x, int y) {
    if (size == 0)return;

    int sum = 0;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            sum += v[i][j];
        }
    }
    if (sum == size * size) { one++; return; }
    if (sum == 0) { zero++; return; }

    compress(v, size / 2, x, y);
    compress(v, size / 2, x + size / 2, y);
    compress(v, size / 2, x, y + size / 2);
    compress(v, size / 2, x + size / 2, y + size / 2);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> v[i][j];
    compress(v, n, 0, 0);

    cout << zero << '\n' << one;
}