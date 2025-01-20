#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, i; cin >> n;
   
    if (n % 6 == 2) {
        for (i = 2; i <= n; i += 2) cout << i << '\n';
        cout << 1 << '\n' << 3 << '\n';
        for (i = 7; i <= n; i += 2) cout << i << '\n';
        cout << 5 << '\n';
    }
    else if (n % 6 == 3) {
        for (i = 4; i <= n; i += 2) cout << i << '\n';
        cout << 2 << '\n';
        for (i = 5; i <= n; i += 2) cout << i << '\n';
        cout << 1 << '\n' << 3 << '\n';
    }
    else {
        for (i = 2; i <= n; i += 2)cout << i << '\n';
        for (i = 1; i <= n; i += 2)cout << i << '\n';
    }
}
