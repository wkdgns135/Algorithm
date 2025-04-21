#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
    {
        int n, d, c; cin >> n >> d >> c;
        vector<vector<pair<int,int>>> graph(n + 1);
        for (int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({ s, a });
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> mdt(n + 1, INT_MAX);
        mdt[c] = 0;
        pq.push({ 0, c });
        while (!pq.empty())
        {
            auto [cost, node] = pq.top();
            pq.pop();
            for (const auto& [nextCost, nextNode] : graph[node])
            {
                if (mdt[nextNode] > mdt[node] + nextCost)
                {
                    mdt[nextNode] = mdt[node] + nextCost;
                    pq.push({ mdt[nextNode], nextNode });
                }
            }
        }
        int cnt = 0, maxVal = 0;
        for (const int& ele : mdt)
        {
            if (ele != INT_MAX)
            {
                cnt++;
                maxVal = max(maxVal, ele);
            }
        }
        cout << cnt << ' ' << maxVal << '\n';
    }
}
