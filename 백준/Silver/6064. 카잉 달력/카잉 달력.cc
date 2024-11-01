#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int result = -1;
        for (int k = x; k <= m * n; k += m) {
            if ((k - 1) % n + 1 == y) {
                result = k;
                break;
            }
        }
        cout << result << '\n';
    }
}
