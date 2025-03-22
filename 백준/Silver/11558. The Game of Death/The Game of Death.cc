#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i]--;
        }
        vector<bool> visited(n);
        visited[0] = true;
        stack<int> dfs;
        dfs.push(0);
        int answer = 0;
        while (!dfs.empty())
        {
            int node = dfs.top();
            dfs.pop();
            if (node == n - 1)
            {
                break;
            }
            if (visited[v[node]])continue;
            visited[v[node]] = true;
            dfs.push(v[node]);
            answer++;
        }
        if (visited[n - 1])cout << answer << '\n';
        else cout << 0 << '\n';
    }
}
