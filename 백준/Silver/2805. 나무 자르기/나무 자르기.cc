#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<long long> v(n + 1), vv(n + 1);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        vv[i] = (v[i-1] - v[i]) * i + vv[i - 1];
        if (!idx && vv[i] >= m)idx = i;
    }

    int answer = *v.begin() - ((*v.begin() - v[idx]) - (vv[idx] - m) / idx);
    cout << answer;
}