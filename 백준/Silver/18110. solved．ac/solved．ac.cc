#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int sum = 0;
    int offset = floor(0.15 * v.size() + 0.5);
    for (int i = offset; i < v.size() - offset; i++) {
        sum += v[i];
    }
    if (n == 0)cout << 0;
    else  cout << floor((double)sum / (v.size() - offset * 2) + 0.5);
}
