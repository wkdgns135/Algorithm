#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<set<int>> v(n + 1, set<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    int minVal = INT_MAX;
    int minIndex = 0;

    for (int i = 1; i <= n; i++) {
        int kb = 0;
        queue<int> bfs;
        vector<int> visited(n + 1, -1);
        bfs.push(i);
        visited[i] = 0;

        while (!bfs.empty()) {
            int node = bfs.front();
            bfs.pop();
            for (auto&next : v[node]) {
                if (visited[next] == -1) {
                    bfs.push(next);
                    visited[next] = visited[node] + 1;
                    kb += visited[next];
                }
            }
            if (kb > minVal)break;
        }
        if (minVal > kb) {
            minVal = kb;
            minIndex = i;
        }
    }
    cout << minIndex;
}
