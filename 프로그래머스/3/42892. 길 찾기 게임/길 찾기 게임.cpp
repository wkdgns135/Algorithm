#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Node{
    int n, x, y;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int n, int x, int y) : n(n), x(x), y(y){}
};

struct cmp{
    bool operator()(Node *a, Node *b){
        if(a->y != b->y) return a->y < b->y;
        return a->x < b->x;
    }
};

void make_graph(Node* node, priority_queue<Node*, vector<Node*>, cmp> &pq){
    priority_queue<Node*, vector<Node*>, cmp> leftHeap, rightHeap;
    
    while(!pq.empty()){
        Node *next = pq.top();
        pq.pop();
        if(node->x < next->x)rightHeap.push(next);
        else leftHeap.push(next);
    }
    
    if(!leftHeap.empty()){
        Node* left = leftHeap.top();
        leftHeap.pop();
        node->left = left;
        make_graph(left, leftHeap);
    }
    
    if(!rightHeap.empty()){
        Node* right = rightHeap.top();
        rightHeap.pop();
        node->right = right;
        make_graph(right, rightHeap);
    }
}

void preorder(Node *node, vector<vector<int>> &answer){
    answer[0].push_back(node->n);
    if(node->left)preorder(node->left, answer);
    if(node->right)preorder(node->right, answer);
}

void postorder(Node *node, vector<vector<int>> &answer){
    if(node->left)postorder(node->left, answer);
    if(node->right)postorder(node->right, answer);
    answer[1].push_back(node->n);
    delete node;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    
    priority_queue<Node*, vector<Node*>, cmp> heap;
    
    for(int i = 1; i <= nodeinfo.size(); i++){
        Node *node = new Node(i, nodeinfo[i-1][0], nodeinfo[i-1][1]);
        heap.push(node);
    }
    
    Node* parent = heap.top();
    heap.pop();
    make_graph(parent, heap);
    
    preorder(parent, answer);
    postorder(parent, answer);
    
    return answer;
}