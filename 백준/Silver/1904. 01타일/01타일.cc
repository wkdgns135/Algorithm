#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n+1);
    v[1] = 1, v[2] = 2;
    for (int i = 3; i <= n; i++) {
        v[i] = v[i - 1] + v[i - 2];
        v[i] %= 15746;
    }
    cout << v[n];
}