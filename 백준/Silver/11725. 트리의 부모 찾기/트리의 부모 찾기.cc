#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n;
    int parent = -1;
    vector<Node*> edges;
    Node() {};
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<Node*> v;
    for (int i = 0; i < n; i++)v.push_back(new Node());

    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        v[x - 1]->n = x - 1;
        v[y - 1]->n = y - 1;

        v[x - 1]->edges.push_back(v[y - 1]);
        v[y - 1]->edges.push_back(v[x - 1]);
    }

    stack<Node*> dfs;
    dfs.push(v[0]);
    v[0]->parent = v[0]->n;

    while (!dfs.empty()) {
        Node* node = dfs.top();
        dfs.pop();
        for (int i = 0; i < node->edges.size(); i++) {
            Node* next = node->edges[i];
            if (next->parent != -1)continue;
            next->parent = node->n;
            dfs.push(next);
        }
    }

    for (int i = 1; i < n; i++)cout << v[i]->parent + 1 << '\n';
}