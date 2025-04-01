#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> indegree(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }
    vector<int> answer;
    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        answer.push_back(node);
        for (const int& next : graph[node])
        {
            indegree[next]--;
            if (indegree[next] == 0)pq.push(next);
        }
    }
    for (const int& node : answer)
    {
        cout << node + 1 << ' ';
    }
}