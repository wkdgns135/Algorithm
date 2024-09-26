#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n;
    vector<Node*> neighbor;
    Node(int n) { this->n = n; }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b; cin >> n >> a >> b >> m;
    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; i++)nodes[i] = new Node(i);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        nodes[a]->neighbor.push_back(nodes[b]);
        nodes[b]->neighbor.push_back(nodes[a]);
    }

    queue<Node*> bfs;
    bfs.push(nodes[a]);
    vector<int> visited(n + 1, -1);
    visited[a] = 0;
    while (!bfs.empty()) {
        Node* node = bfs.front();
        bfs.pop();
        if (node->n == b) {
            cout << visited[node->n];
            return 0;
        }
        for (auto neighbor : node->neighbor) {
            if (visited[neighbor->n] != -1)continue;
            visited[neighbor->n] = visited[node->n] + 1;
            bfs.push(neighbor);
        }
    }

    cout << -1;
}