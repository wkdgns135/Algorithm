#include <bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<vector<int>>& graph, int s, int e) {
    vector<bool> visited(n, false);
    queue<int> bfs;
    bfs.push(s);
    visited[s] = true;
    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        if (node == e) return true;
        for (auto& next : graph[node]) {
            if (visited[next]) continue;
            visited[next] = true;
            bfs.push(next);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, s, e, m; cin >> n >> s >> e >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> graph(n);
    vector<int> values(n);
    for (int i = 0; i < m; i++) {
        cin >> get<0>(edges[i]) >> get<1>(edges[i]) >> get<2>(edges[i]);
        graph[get<0>(edges[i])].push_back(get<1>(edges[i]));
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<long long> mdt(n, LLONG_MAX);
    mdt[s] = -values[s];

    // 벨만-포드 알고리즘으로 최단 경로 구하기
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int from = get<0>(edges[j]);
            int to = get<1>(edges[j]);
            int cost = get<2>(edges[j]);
            if (mdt[from] != LLONG_MAX && mdt[to] > mdt[from] + cost - values[to]) {
                mdt[to] = mdt[from] + cost - values[to];
            }
        }
    }

    // 음수 사이클 탐지
    bool negativeCycleDetected = false;
    for (int j = 0; j < m; j++) {
        int from = get<0>(edges[j]);
        int to = get<1>(edges[j]);
        int cost = get<2>(edges[j]);
        if (mdt[from] != LLONG_MAX && mdt[to] > mdt[from] + cost - values[to]) {
            // 음수 사이클 발견
            negativeCycleDetected = true;
            if (bfs(n, graph, s, to) && bfs(n, graph, to, e)) {
                cout << "Gee";
                return 0;
            }
        }
    }

    if (mdt[e] == LLONG_MAX) {
        cout << "gg";
    }
    else {
        cout << -mdt[e];
    }
}
