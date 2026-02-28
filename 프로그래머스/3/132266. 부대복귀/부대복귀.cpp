#include <queue>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size());
    vector<vector<int>> graph(n + 1);
    
    for(auto &road : roads){
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    vector<int> mdt(n + 1, 100000);
    queue<int> bfs;
    bfs.push(destination);
    mdt[destination] = 0;
    
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        
        for(int next : graph[node]){
            if(mdt[next] > mdt[node] + 1){
                mdt[next] = mdt[node] + 1;
                bfs.push(next);
            }
        }
    }
    
    for(int i = 0; i < sources.size(); i++){
        answer[i] = mdt[sources[i]] == 100000 ? -1 : mdt[sources[i]];
    }
    return answer;
}