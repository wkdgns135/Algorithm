#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    string answer = "";
    vector<vector<int>> v(n + 1);
    vector<int> id(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        id[b]++;
    }
    queue<int> bfs;
    for (int i = 1; i <= n; i++)if (!id[i])bfs.push(i);
    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        answer += to_string(node) + ' ';
        for (auto& next : v[node]) {
            id[next]--;
            if (!id[next])bfs.push(next);
        }
        v[node].clear();
    }
    cout << answer;
}
