#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first)return a.first < b.first;
        return a.second < b.second;
        });

    for (int i = 0; i < n; i++) {
        if (s.empty()) { s.push(v[i]); continue; }
        if (s.top().second <= v[i].first) s.push(v[i]);
        else if (s.top().first <= v[i].first && s.top().second > v[i].second) {
            s.pop();
            s.push(v[i]);
        }
        else if (s.top().first < v[i].first && s.top().second >= v[i].second) {
            s.pop();
            s.push(v[i]);
        }
    }
    cout << s.size();
}