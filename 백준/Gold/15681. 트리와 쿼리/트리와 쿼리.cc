#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n;
    Node* parent = nullptr;
    vector<Node*> child;
    vector<Node*> neighbor;
    Node(int n) { this->n = n; };
};

vector<Node*> tree;
vector<int> nodeCount;
void MakeTree(Node* currentNode, Node* parent) {
    for (Node* node : currentNode->neighbor) {
        if (node == parent)continue;
        currentNode->child.push_back(node);
        node->parent = currentNode;
        MakeTree(node, currentNode);
    }
}

void CountSubtreeNodes(Node* currentNode) {
    nodeCount[currentNode->n] = 1;
    for (Node* node : currentNode->child) {
        CountSubtreeNodes(node);
        nodeCount[currentNode->n] += nodeCount[node->n];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, R, Q; cin >> N >> R >> Q;
    tree.resize(N);
    nodeCount.resize(N);

    for (int i = 0; i < N; i++) {
        tree[i] = new Node(i);
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        tree[u]->neighbor.push_back(tree[v]);
        tree[v]->neighbor.push_back(tree[u]);
    }
    
    MakeTree(tree[R - 1], tree[R - 1]);
    CountSubtreeNodes(tree[R - 1]);
    while (Q--) {
        int u; cin >> u;
        u--;
        cout << nodeCount[u] << '\n';
    }
}
