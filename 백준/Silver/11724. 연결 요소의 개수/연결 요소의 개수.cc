#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>());
    vector<bool> visited(n);
    
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (visited[i])continue;
        stack<int> dfs;
        dfs.push(i);
        visited[i] = true;
        count++;
        while (!dfs.empty()) {
            int index = dfs.top();
            dfs.pop();
            for (int j = 0; j < v[index].size(); j++) {
                if (visited[v[index][j]])continue;
                visited[v[index][j]] = true;
                dfs.push(v[index][j]);
            }
        }
    }
    cout << count << '\n';
}