#include <bits/stdc++.h>
using namespace std;

int n, e, v1, v2;

int FindShortcut(vector<vector<pair<int, int>>> &v, int start, int end) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<int> mdt(n, INT_MAX);
    pq.push({ 0, start});
    mdt[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (cost != mdt[node])continue;
        if (node == end)break;
        for (auto& edge : v[node]) {
            if (mdt[edge.first] > edge.second + cost) {
                mdt[edge.first] = edge.second + cost;
                pq.push({ mdt[edge.first], edge.first });
            }
        }
    }

    return mdt[end];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> e;
    vector<vector<pair<int,int>>> v(n, vector<pair<int,int>>());
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a - 1].push_back({ b - 1, c });
        v[b - 1].push_back({ a - 1, c });
    }
    cin >> v1 >> v2;
    v1--, v2--;

    int av1 = FindShortcut(v, 0, v1), v1v2 = FindShortcut(v, v1, v2), v2n = FindShortcut(v, v2, n - 1);
    int av2 = FindShortcut(v, 0, v2), v1n = FindShortcut(v, v1, n - 1);

    if (av1 == INT_MAX || v1v2 == INT_MAX || v2n == INT_MAX) { cout << -1; return 0; }
    if (av2 == INT_MAX || v1n == INT_MAX) { cout << -1; return 0; }
    
    cout << min(av1 + v1v2 + v2n, av2 + v1v2 + v1n);
}