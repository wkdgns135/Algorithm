#include <bits/stdc++.h>
using namespace std;

int func(int n, int k) {
    if (k == 0 || k == n) return 1;
    return func(n - 1, k - 1) + func(n - 1, k);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    cout << func(n, k);
}
