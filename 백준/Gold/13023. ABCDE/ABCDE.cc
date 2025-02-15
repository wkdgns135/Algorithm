#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
bool bFound = false;
void DFS(int depth, int node, vector<bool> &visited) 
{
    if (bFound)return;
    if (depth == 4) {
        bFound = true;
        return;
    }
    for (const int& next : graph[node]) {

        if (visited[next])continue;
        visited[next] = true;
        DFS(depth + 1, next, visited);
        visited[next] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n);
        visited[i] = true;
        DFS(0, i, visited);
        if (bFound)break;
    }
    cout << bFound;
}
