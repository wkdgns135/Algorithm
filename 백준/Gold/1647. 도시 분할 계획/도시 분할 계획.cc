#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int node, cost;
    bool operator()(Edge a, Edge b) {
        return a.cost > b.cost;
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    priority_queue <Edge, vector<Edge>, Edge> pq;
    vector<bool> visited(n);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a - 1].push_back({ b - 1, c });
        graph[b - 1].push_back({ a - 1, c });
    }

    for (auto& i : graph[0]) {
        pq.push({ i.node, i.cost});
    }

    visited[0] = true;
    vector<int> result;
    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
;       pq.pop();

        if (!visited[node]) {
            result.push_back(cost);
            visited[node] = true;
            for (auto& next : graph[node]) {
                if (visited[next.node])continue;
                pq.push({next.node, next.cost});
            }
        }
    }
    cout << accumulate(result.begin(), result.end(), 0) - *max_element(result.begin(), result.end());
}
