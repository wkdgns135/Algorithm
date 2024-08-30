#include <bits/stdc++.h>
using namespace std;

struct Node {
    char key;
    Node* left = nullptr;
    Node* right = nullptr;
};

void PreOrder(Node *node) {
    if (node == nullptr)return;
    cout << node->key;
    PreOrder(node->left);
    PreOrder(node->right);
}

void InOrder(Node* node) {
    if (node == nullptr)return;
    InOrder(node->left);
    cout << node->key;
    InOrder(node->right);
}

void PostOrder(Node* node) {
    if (node == nullptr)return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->key;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<Node*> v(n); for (int i = 0; i < n; i++)v[i] = new Node();

    while (n--) {
        char key, left, right; cin >> key >> left >> right;
        v[key - 'A']->key = key;
        v[key - 'A']->left = left == '.' ? nullptr : v[left - 'A'];
        v[key - 'A']->right = right == '.' ? nullptr : v[right - 'A'];
       
    }

    PreOrder(v[0]); cout << '\n';
    InOrder(v[0]); cout << '\n';
    PostOrder(v[0]);
}
