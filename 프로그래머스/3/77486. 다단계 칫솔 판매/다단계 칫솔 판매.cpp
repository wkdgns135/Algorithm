#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


struct Node{
    Node* parent = nullptr;
    int cost = 0;
    
    Node(){};
};

int n, m;
unordered_map<string, Node> graph;

void dfs(Node* node, int cost){
    if(cost == 0)return;
    int tax = cost * 0.1;
    node->cost += cost - tax;
    if(!node->parent)return;
    dfs(node->parent, tax);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
	n = enroll.size(), m = seller.size();
	vector<int> answer(n);
	graph["-"] = Node();

	for (int i = 0; i < n; i++){ 
        graph[enroll[i]] = Node();
        graph[enroll[i]].parent = &graph[referral[i]];
    }
    
	for (int i = 0; i < m; i++) dfs(&graph[seller[i]], amount[i] * 100);
	for (int i = 0; i < n; i++) answer[i] = graph[enroll[i]].cost;

	return answer;
}