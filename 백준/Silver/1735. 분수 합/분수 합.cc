#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, x, y; cin >> a >> b >> x >> y;
    int l = lcm(b, y);
    int eq = l / b * a + l / y * x;
    int g = gcd(eq, l);
    cout << eq / g << ' ' << l / g;
}
