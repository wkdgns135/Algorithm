#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);

    int n; cin >> n;
    vector<int> lis;
    vector<int> idx(n), pre(n, -1);
    vector<int> v(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        int pos = it - lis.begin();

        if (it == lis.end()) lis.push_back(v[i]);
        else *it = v[i];

        idx[pos] = i;
        if (pos > 0) pre[i] = idx[pos - 1];
    }

    cout << lis.size() << '\n';
    int t = idx[lis.size() - 1];
    while (t != -1) {s.push(t); t = pre[t]; }
    while (!s.empty()) { cout << v[s.top()] << ' '; s.pop(); }
}
