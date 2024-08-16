#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N, M, V;
void dfs(int n, int& depth, unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& isVisit) {
    if (depth == N)return;
    cout << n << ' ';

    sort(graph[n].begin(), graph[n].end());
    for (int i : graph[n]) {
        if (isVisit[i])continue;
        isVisit[i] = true;
        dfs(i, ++depth, graph, isVisit);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> V;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> isVisit;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //DFS
    
    isVisit[V] = true;
    int depth = 0;
    dfs(V, depth, graph, isVisit);
    cout << "\n";

    //BFS
    queue<int> bfs;
    bfs.push(V);

    isVisit.clear();
    isVisit[V] = true;
    while (!bfs.empty()) {
        int n = bfs.front();
        cout << n << ' ';
        bfs.pop();
        sort(graph[n].begin(), graph[n].end());
        for (int i : graph[n]) {
            if (isVisit[i])continue;
            isVisit[i] = true;
            bfs.push(i);
            
        }
    }

    return 0;
}