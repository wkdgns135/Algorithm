#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, i; cin >> n;

    for (i = 1; i < n; i++) {
        string s = to_string(i);
        int sum = i;
        for (auto& ch : s)sum += ch - '0';
        if (sum == n)break;
    }

    if (i < n)cout << i;
    else cout << 0;
}