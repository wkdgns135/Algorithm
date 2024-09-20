#include <bits/stdc++.h>
using namespace std;

int r, c;
void DivideConquer(int n, int x, int y, long long value) {
    if (n == 1) {
        if (y == r && x == c) cout << value;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int xx = (i % 2) * (n / 2) + x;
        int yy = (i / 2) * (n / 2) + y;
        if(xx <= c && c < xx + n / 2 && yy <= r && r < yy + n / 2) DivideConquer(n / 2, xx, yy, value + (n * n / 4 * i));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n >> r >> c;
    DivideConquer(pow(2, n), 0, 0, 0);
}