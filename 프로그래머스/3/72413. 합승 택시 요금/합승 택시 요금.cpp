#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> search(vector<vector<pair<int, int>>>& graph, int start)
{
    vector<int> mdt(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, start});
    mdt[start] = 0;
    
    while(!heap.empty()){
        auto [cost, node] = heap.top();
        heap.pop();
        
        if(mdt[node] != cost) continue;
        
        for(auto [nextNode, nextCost] : graph[node]){
            if(mdt[nextNode] > cost + nextCost){
                mdt[nextNode] = cost + nextCost;
                heap.push({mdt[nextNode], nextNode});
            }
        }
    }

    return mdt;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INT_MAX;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (const auto& fare : fares)
    {
        graph[fare[0]].push_back({ fare[1], fare[2] });
        graph[fare[1]].push_back({ fare[0], fare[2] });
    }
    
    vector<vector<int>> mdts(3);
    mdts[0] = search(graph, s);
    mdts[1] = search(graph, a);
    mdts[2] = search(graph, b);
    
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 0; j < 3; j++){
            sum += mdts[j][i];
        }
        answer = min(answer, sum);
    }
    
    return answer;
}