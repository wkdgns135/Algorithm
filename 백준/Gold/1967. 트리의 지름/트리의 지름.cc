#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;

// 가장 먼 노드와 거리를 반환하는 DFS 함수
pair<int, int> dfs(int node, int dist, vector<bool>& visited) {
    visited[node] = true;
    pair<int, int> farthest = { dist, node };

    for (auto& next : graph[node]) {
        if (!visited[next.first]) {
            pair<int, int> candidate = dfs(next.first, dist + next.second, visited);
            if (candidate.first > farthest.first) {
                farthest = candidate;
            }
        }
    }

    return farthest;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    // 1번 DFS: 임의의 노드에서 가장 먼 노드 찾기
    vector<bool> visited(n + 1, false);
    pair<int, int> first = dfs(1, 0, visited);

    // 2번 DFS: 첫 번째 DFS에서 찾은 노드에서 가장 먼 노드 찾기
    fill(visited.begin(), visited.end(), false);
    pair<int, int> second = dfs(first.second, 0, visited);

    // 트리의 지름 출력
    cout << second.first << '\n';
}
