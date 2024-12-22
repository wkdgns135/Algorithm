#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    vector<int> v(s.size());
    for (int i = 0; i < s.size(); i++) {
        v[i] = s[i] - '0';
    }
    if (find(v.begin(), v.end(), 0) == v.end() || accumulate(v.begin(), v.end(), 0) % 3 != 0) {
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end(), greater<int>());
    for (auto& i : v)cout << i;
}
