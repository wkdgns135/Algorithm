#include <bits/stdc++.h>
using namespace std;

struct Link {
    char c;
    Link* left;
    Link* right;

    Link(char c = NULL) {
        this->c = c;
        left = nullptr;
        right = nullptr;
    };

    Link* D() {
        if (right == nullptr)return this;
        return right;
    }
    Link* L() {
        if (left->c == 0)return this;
        return left;
    }
    void B() {
        if (left->c == 0)return;
        left = left->left;
        left->right = this;
    }
    void P(char c) {
        Link* l = new Link(c);
        if (left != nullptr)left->right = l;
        l->left = left;
        l->right = this;
        left = l;
    }
};

void PrintLink(Link *l) {
    while (l->right != nullptr) {
        cout << l->c;
        l = l->right;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    int m; cin >> m;
    Link *begin = new Link(), * end = new Link();
    Link* left = begin;
    for (int i = 0; i < str.size(); i++) {
        Link* link = new Link(str[i]);
        if (i == str.size() - 1) {
            end->left = link;
            link->right = end;
        }
        left->right = link;
        link->left = left;
        left = link;
    }
    Link* cursor = end;
    while (m--) {
        char command; cin >> command;
        if (command == 'L')cursor = cursor->L();
        if (command == 'D')cursor = cursor->D();
        if (command == 'B')cursor->B();
        if (command == 'P') {
            char c; cin >> c;
            cursor->P(c);
        }
    }
    PrintLink(begin->right);
}
