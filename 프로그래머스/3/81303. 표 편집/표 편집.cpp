#include <string>
#include <vector>

using namespace std;

struct Node{
    Node* prev = nullptr;
    Node* next = nullptr;
    bool erased = false;
    
    void restore(){
        erased = false;
        if(next) next->prev = this;
        if(prev) prev->next = this;
    }
    
    void erase(){
        erased = true;
        if(next) next->prev = prev;
        if(prev) prev->next = next;
    }
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    vector<Node> graph;
    graph.resize(n);
    graph[0].next = &graph[1], graph[n - 1].prev = &graph[n - 2];
    for(int i = 1; i < n - 1; i++){
        graph[i].prev = &graph[i - 1];
        graph[i].next = &graph[i + 1];
    }
    
    Node* curr = &graph[k];
    vector<Node*> stack;
    
    for(auto &row : cmd){
        if(row.size() > 1){
            int x = stoi(row.substr(2));
            if(row[0] == 'U'){
                for(int i = 0; i < x; i++) curr = curr->prev;
            }else{ // row[0] == 'D'
                for(int i = 0; i < x; i++) curr = curr->next;
            }
        }else{
            if(row == "C"){
                stack.push_back(curr);
                curr->erase();
                curr = curr->next == nullptr ? curr->prev : curr->next;
            }
            else{ // row == 'Z'
                Node *node = stack.back();
                node->restore();
                stack.pop_back();
            }
        }
    }
    
    for(int i = 0; i < n; i++) if(graph[i].erased)answer[i] = 'X';
    
    return answer;
}