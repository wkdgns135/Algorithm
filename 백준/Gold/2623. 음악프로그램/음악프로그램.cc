#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &graph, vector<bool> &finish, vector<int> &visited, int &order, bool &isCycle) {
    if (isCycle)return;
    visited[node] = order++;
    
    for (int& next : graph[node]) {
        if (visited[next] == 0) {
            dfs(next, graph, finish, visited, order, isCycle);
        }
        else if (!finish[next]) {
            isCycle = true;
            return;
        }
    }
    finish[node] = true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> depth(n + 1);
    vector<vector<int>> v(m);
    for (int i = 0; i < m; i++) {
        int size, prev; cin >> size >> prev;
        for (int j = 1; j < size; j++) {
            int node; cin >> node;
            graph[prev].push_back(node);
            depth[node]++;
            prev = node;
        }
    }

    vector<bool> finish(n + 1);
    vector<int> visited(n + 1);
    priority_queue<pair<int, int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    int order = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] == 0) {
            bool result = false;
            dfs(i, graph, finish, visited, order, result);
            if (result) {
                cout << 0 << '\n';
                return 0;
            }
            pq.push({ 0, i });
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        int node, d; 
        tie(d, node) = pq.top();
        pq.pop();
        result.push_back(node);

        for (int& next : graph[node]) {
            if(--depth[next] == 0)pq.push({ depth[next], next});
        }
    }
    for (int& node : result)cout << node << '\n';
}
