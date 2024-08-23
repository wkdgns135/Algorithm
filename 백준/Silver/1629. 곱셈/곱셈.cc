#include <bits/stdc++.h>
using namespace std;

long long sol(long long a, long long b, long long c) {
    if (b == 0)return 1;
    if (b % 2 == 0) {
        long long half = sol(a, b / 2, c);
        return (half * half) % c;
    }
    else {
        return (a * sol(a, b - 1, c)) % c;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long a, b, c; cin >> a >> b >> c;
    cout << sol(a, b, c);
}
