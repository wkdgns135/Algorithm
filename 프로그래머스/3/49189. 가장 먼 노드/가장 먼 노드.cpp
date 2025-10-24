#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> visited(n + 1 , -1);
    queue<int> bfs;
    bfs.push(1);
    visited[1] = 0;
    
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        for(int next : graph[node]){
            if(visited[next] == -1){
                visited[next] = visited[node] + 1;
                bfs.push(next);
            }
        }
    }
    
    int maxVal = 0;
    for(int i : visited){
        if(i > maxVal){
            maxVal = i;
            answer = 1;
        }else if(i == maxVal)answer++;
    }
    
    return answer;
}