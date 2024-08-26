#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int num_nodes = 1;

    for (int i = 0; i < adj[node].size(); ++i) {
        int next_node = adj[node][i];
        if (!visited[next_node]) {
            num_nodes += dfs(next_node);
        }
    }

    return num_nodes;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    adj.resize(n + 1);
    for (const auto& wire : wires) {
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }

    for (const auto& wire : wires) {
        visited.assign(n + 1, false);
        visited[wire[0]] = true;
        int nodes = dfs(wire[1]);
        answer = min(answer, abs((n - nodes) - nodes));
    }

    return answer;
}