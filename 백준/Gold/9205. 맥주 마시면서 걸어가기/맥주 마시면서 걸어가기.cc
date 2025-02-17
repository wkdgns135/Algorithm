#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n;
    int x, y;
    vector<Node*> edge;
    int operator-(const Node &b) {
        return abs(x - b.x) + abs(y - b.y);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, n, x, y; cin >> t;
    while (t--) {
        cin >> n;
        int s = 0, e = n + 1, size = n + 2;
        vector<Node> v(size);

        v[s].n = s;
        cin >> v[s].x >> v[s].y;
        for (int i = 1; i <= n; i++) {
            v[i].n = i;
            cin >> v[i].x >> v[i].y;
        }
        v[e].n = e;
        cin >> v[e].x >> v[e].y;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (i == j)continue;
                if (v[i] - v[j] <= 1000) {
                    v[i].edge.push_back(&v[j]);
                    v[j].edge.push_back(&v[i]);
                }
            }
        }

        vector<bool> visited(size);
        queue<Node*> bfs;
        bfs.push(&v[s]);
        visited[s] = true;

        while (!bfs.empty()) {
            Node* node = bfs.front();
            bfs.pop();
            if (node->n == e)break;
            for (Node* next : node->edge) {
                if (visited[next->n])continue;
                bfs.push(next);
                visited[next->n] = true;
            }
        }
        if (visited[e])cout << "happy\n";
        else cout << "sad\n";
    }
}
