#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int answer = INT_MAX;

int search(vector<vector<pair<int, int>>>& graph, int start, int end)
{
    vector<int> mdt(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, start});
    mdt[start] = 0;
    
    while(!heap.empty()){
        auto [cost, node] = heap.top();
        heap.pop();
        
        if(mdt[node] != cost) continue;
        if(node == end) break;
        
        for(auto [nextNode, nextCost] : graph[node]){
            if(mdt[nextNode] > cost + nextCost){
                mdt[nextNode] = cost + nextCost;
                heap.push({mdt[nextNode], nextNode});
            }
        }
    }

    return mdt[end];
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

    queue<int> bfs;
    vector<int> mdt(graph.size(), INT_MAX);
    bfs.push(s);
    mdt[s] = 0;
    
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        
        if(answer > mdt[node]){
            int A = search(graph, node, a);
            if(answer > mdt[node] + A){
                int B = search(graph, node, b);
                if(answer > mdt[node] + A + B)answer = mdt[node] + A + B;
            }
        }
        
        for(auto [next, cost] : graph[node]){
            if(mdt[next] > mdt[node] + cost && answer > mdt[node] + cost){
                mdt[next] = mdt[node] + cost;
                bfs.push(next);
            }
        }
    }
    
    return answer;
}