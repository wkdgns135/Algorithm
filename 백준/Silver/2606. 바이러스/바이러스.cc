#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    
    vector<bool> visited(n);
    vector<vector<int>> v(n, vector<int>());
    while (m--) {
        int i, j; cin >> i >> j;
        v[i - 1].push_back(j - 1);
        v[j - 1].push_back(i - 1);
    }
    stack<int> dfs;
    dfs.push(0);
    visited[0] = true;

    int count = 0;
    while (!dfs.empty()) {
        int index = dfs.top();
        dfs.pop();

        for (int i = 0; i < v[index].size(); i++) {
            if (visited[v[index][i]])continue;
            visited[v[index][i]] = true;
            dfs.push(v[index][i]);
            count++;
        }
    }
    cout << count;
}