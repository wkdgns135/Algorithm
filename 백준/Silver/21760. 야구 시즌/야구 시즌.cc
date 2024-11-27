#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, m, k, d; cin >> t;
    while (t--) {
        cin >> n >> m >> k >> d;
        int b = 1, a = b * k;
        auto same = [&n, &m, &a]() {return  n * m * (m - 1) * a / 2; };
        auto other = [&n, &m, &b]() {return n * m * (n - 1) * m * b / 2; };
        for (b = 1; same() + other() <= d; b++, a = b * k);
        b--, a = b * k;
        if (b == 0)cout << -1 << '\n';
        else cout << same() + other() << '\n';
    }
}
