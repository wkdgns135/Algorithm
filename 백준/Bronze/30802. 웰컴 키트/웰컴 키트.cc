#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int answer = 0;
    vector<double> v(6); for (int i = 0; i < 6; i++) cin >> v[i];
    int t, p; cin >> t >> p;
    for (auto& i : v) answer += ceil(i / t);
    cout << answer << '\n';
    cout << n / p << ' ' <<  n % p;
}
