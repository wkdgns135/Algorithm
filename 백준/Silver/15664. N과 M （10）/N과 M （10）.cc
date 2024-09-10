#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v, vv;
set<vector<int>> s;
vector<bool> visited;
void BackTracking(int depth, int index) {
    if (depth == m) {
        s.insert(vector<int>(vv));
        return;
    }

    for (int i = index; i < n; i++) {
        if (visited[i])continue;
        visited[i] = true;
        vv[depth] = v[i];
        BackTracking(depth + 1, i + 1);
        visited[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v = vector<int>(n), vv = vector<int>(m), visited = vector<bool>(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    BackTracking(0, 0);
    
    for (auto &i : s) {
        for (auto& j : i) cout << j << ' ';
        cout << '\n';
    }
}
