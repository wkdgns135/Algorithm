#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v, vv;
set<vector<int>> s;

void BackTracking(int depth) {
    if (depth == m) {
        s.insert(vv);
        return;
    }

    for (int i = 0; i < n; i++) {
        vv[depth] = v[i];
        BackTracking(depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v = vector<int>(n), vv = vector<int>(m);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    BackTracking(0);
    
    for (auto &i : s) {
        for (auto& j : i) cout << j << ' ';
        cout << '\n';
    }
}
