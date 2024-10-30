#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin >> k;
    

    while (k--) {
        int v, e; cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        for (int i = 0; i < e; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> visited(v + 1, -1);
        queue<int> bfs;
        bool flag = false;
        for (int i = 1; i <= v; i++) {
            if (visited[i] != -1)continue;
            bfs.push(i);
            visited[i] = 0;
            while (!bfs.empty()) {
                int node = bfs.front();
                bfs.pop();
                for (auto& next : graph[node]) {
                    if (visited[next] == -1) {
                        visited[next] = !visited[node];
                        bfs.push(next);
                    }
                    else if (visited[next] != !visited[node]) {
                        bfs = queue<int>();
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
