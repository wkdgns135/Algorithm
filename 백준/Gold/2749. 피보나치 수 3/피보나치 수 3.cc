#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;
void func(vector<long long>& a, vector<long long>& b) {
    long long r0 = (a[0] * b[0] + a[1] * b[2]) % MOD;
    long long r1 = (a[0] * b[1] + a[1] * b[3]) % MOD;
    long long r2 = (a[2] * b[0] + a[3] * b[2]) % MOD;
    long long r3 = (a[2] * b[1] + a[3] * b[3]) % MOD;
    a[0] = r0, a[1] = r1, a[2] = r2, a[3] = r3;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    vector<long long> a = { 1,1,1,0 };
    vector<long long> b = { 1,0,0,1 };

    while (n) {
        if (n % 2 == 1)func(b, a);
        n >>= 1;
        func(a, a);
    }
    cout << b[1] << '\n';
}