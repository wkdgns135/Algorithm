#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    long double sum = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        sum += v[i].first * v[next].second - v[next].first * v[i].second;
    }

    cout <<  fixed << setprecision(1) << abs(sum) * 0.5;
}
