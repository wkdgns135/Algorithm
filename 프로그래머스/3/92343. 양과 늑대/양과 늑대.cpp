#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> info, visited;
int answer = 0;

void bt(int node, int wolf, int sheep){
    answer = max(sheep, answer);
    for(int next : graph[node]){
        if(info[next]){
            if(visited[next]){
                bt(next, wolf, sheep);
            }else if(wolf + 1 < sheep){
                visited[next] = 1;
                bt(next, wolf + 1, sheep);
                visited[next] = 0;
            }
        }else{
            if(visited[next]){
                bt(next, wolf, sheep);
            }else{
                visited[next] = 1;
                bt(0, wolf, sheep + 1);
                visited[next] = 0;
            }
        }
    }
}

int solution(vector<int> in_info, vector<vector<int>> edges) {
    info = move(in_info);
    graph.resize(info.size());
    visited.resize(info.size());
    
    for(auto& edge : edges){
        graph[edge[0]].push_back(edge[1]);
    }
    
    bt(0, 0, 1);
    
    return answer;
}