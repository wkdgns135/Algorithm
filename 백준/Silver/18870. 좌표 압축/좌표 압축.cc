#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector<int> v;
    vector<int> vv;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        v.push_back(input);
        vv.push_back(input);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++) map[v[i]] = i + 1;
    for (int i = 0; i < n; i++) cout << map[vv[i]] - 1 << ' ';
}