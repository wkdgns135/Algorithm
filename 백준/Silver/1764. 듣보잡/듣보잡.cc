#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int m, n; cin >> n >> m;
    unordered_map<string, int> map;
    vector<string> v;
    string str;
    while (n--) { cin >> str; map[str]++; }
    while (m--) { cin >> str; map[str]++; }
    for (auto i : map)if (i.second == 2)v.push_back(i.first);
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto i : v)cout << i << '\n';
}