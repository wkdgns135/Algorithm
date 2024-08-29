#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>());
    vector<pair<int, bool>> mdt(n, { INT_MAX, false });
    for (int i = 0; i < m; i++) {
        int from, dst, cost; cin >> from >> dst >> cost;
        v[from - 1].push_back({ dst - 1, cost });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, k - 1});
    mdt[k - 1] = { 0, false };

    while (!pq.empty()) {
        int cost = pq.top().first;
        int index = pq.top().second;
        pq.pop();

        if (mdt[index].second)continue;
        mdt[index].second = true;

        for (auto& edge : v[index]) {
            int nextIndex = edge.first;
            int nextCost = edge.second;

            if (mdt[nextIndex].first > nextCost + cost) {
                mdt[nextIndex].first = nextCost + cost;
                pq.push({ mdt[nextIndex].first, nextIndex });
            }
        }
    }
    for (auto i : mdt)cout << (i.first == INT_MAX ? "INF" : to_string(i.first)) << '\n';
}
