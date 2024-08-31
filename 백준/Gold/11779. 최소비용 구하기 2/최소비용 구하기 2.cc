#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int n, m, start, end; cin >> n >> m;
    
    vector<vector<pair<int, int>>> v(n);
    vector<int> mdt(n, INT_MAX), pre(n, -1), s;
    
    for (int i = 0; i < m; i++) {
        int from, dst, cost; cin >> from >> dst >> cost;
        v[from-1].push_back({ dst-1, cost });
    }
    cin >> start >> end; start--, end--;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    mdt[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (cost != mdt[node])continue;

        for (auto& edge : v[node]) {
            if (mdt[edge.first] > cost + edge.second) {
                mdt[edge.first] = cost + edge.second;
                pq.push({ mdt[edge.first], edge.first });
                pre[edge.first] = node;
            }
        }
    }
    cout << mdt[end] << '\n';
    while (end != -1) { s.push_back(end); end = pre[end]; }
    cout << s.size() << '\n';
    while (!s.empty()) { cout << s.back() + 1 << ' '; s.pop_back(); }
}
