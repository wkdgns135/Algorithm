#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            if (num)v[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            stack<int> dfs;
            dfs.push(i);
            vector<bool> visited(n);
            int node = dfs.top();
            while (!dfs.empty()) {
                node = dfs.top();
                if (node == j && visited[node])break;
                dfs.pop();
                for (int& next : v[node]) {
                    if (visited[next])continue;
                    visited[next] = true;
                    dfs.push(next);
                }
            }
            cout << visited[j] << ' ';
        }
        cout << '\n';
    }
}