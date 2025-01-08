#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, N, K, W; cin >> T;

    while (T--) {
        // 입력 
        cin >> N >> K;
        vector<vector<int>> graph(N + 1), refGraph(N + 1);
        vector<int> cost(N + 1), indegree(N + 1);
        
        for (int i = 1; i <= N; i++) {
            cin >> cost[i];
        }
        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            refGraph[b].push_back(a);
            indegree[b]++;
        }
        cin >> W;

        // 위상 정렬
        vector<int> sortedGraph;
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (!indegree[i])q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sortedGraph.push_back(node);
            for (const int& next : graph[node]) {
                indegree[next]--;
                if (!indegree[next]) {
                    q.push(next);
                }
            }
        }

        //Dp
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; i++) {
            int node = sortedGraph[i - 1];
            int maxCost = 0;
            for (const int& ref : refGraph[node]) {
                maxCost = max(maxCost, dp[ref]);
            }
            dp[node] += maxCost + cost[node];
        }

        cout << dp[W] << '\n';
    }
}
