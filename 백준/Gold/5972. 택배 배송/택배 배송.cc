#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });
    vector<int> mdt(n + 1, INT_MAX);
    mdt[1] = 0;
    while (!pq.empty()) {
        int node, cost;
        tie(cost, node) = pq.top();
        pq.pop();
        if (mdt[node] != cost)continue;
        if (node == n)break;
        for (auto& next : graph[node]) {
            int nextNode, nextCost;
            tie(nextCost, nextNode) = next;
            if (mdt[nextNode] <= nextCost + mdt[node])continue;
            mdt[nextNode] = nextCost + mdt[node];
            pq.push({mdt[nextNode], nextNode});
        }
    }
    cout << mdt[n];
}
