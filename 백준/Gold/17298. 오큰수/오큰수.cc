#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n, -1);
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (s.empty() || s.top().first > num)s.push({ num, i });
        else {
            while (!s.empty() && s.top().first < num) {
                v[s.top().second] = num;
                s.pop();
            }
            s.push({num, i});
        }
    }
    for (auto& i : v)cout << i << ' ';
}