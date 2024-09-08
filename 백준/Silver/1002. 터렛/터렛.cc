#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        float x1, y1, r1, x2, y2, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int r_ = max(r1, r2), r = min(r1, r2);

        float d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        if (d < r_ + r && d > r_ - r) cout << 2 << '\n';
        else if (d == r_ + r || (r_ - r == d && d != 0)) cout << 1 << '\n';
        else if (d < r_ - r || r_ + r < d || (d == 0 && r_ != r)) cout << 0 << '\n';
        else cout << -1 << '\n';
    }
}
