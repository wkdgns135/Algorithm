#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    unordered_map<string, int> m;
    while (n--) {
        string s1, s2; cin >> s1 >> s2;
        m[s1]++;
    }
    vector<string> v;
    for (auto& i : m)if (i.second % 2 == 1)v.push_back(i.first);
    sort(v.begin(), v.end(), greater<string>());
    for (auto& i : v)cout << i << '\n';
}
