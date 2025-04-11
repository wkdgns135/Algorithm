#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, s, m; cin >> n >> s >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    stack<pair<int, int>> dfs;
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1));

    dfs.push({ s, 0 });
    
    int answer = -1;
    while (!dfs.empty())
    {
        auto [num, index] = dfs.top();
        dfs.pop();
        if (index == n)
        {
            answer = max(answer, num);
            continue;
        }
        int plus = num + v[index];
        int minus = num - v[index];
        if (plus <= m && !visited[plus][index + 1])
        {
            visited[plus][index + 1] = true;
            dfs.push({ plus, index + 1 });
        }
        if (minus >= 0 && !visited[minus][index + 1])
        {
            visited[minus][index + 1] = true;
            dfs.push({ minus, index + 1 });
        }
    }
    cout << answer;
}
