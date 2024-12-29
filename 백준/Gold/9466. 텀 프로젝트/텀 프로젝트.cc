#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        vector<bool> group(n), noGroup(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (--v[i] == i)group[i] = true;
        }

        for (int i = 0; i < n; i++) {
            if (group[i])continue;
            stack<int> dfs;
            vector<int> temp;
            vector<bool> visited(n);
            visited[i] = true;
            dfs.push(i);
            while (!dfs.empty()) {
                int node = dfs.top();
                dfs.pop();
                int next = v[node];

                if (next == i) {
                    for (auto& t : temp) group[t] = true;
                    group[next] = true;
                    break;
                }

                if (group[next] || noGroup[next]) {
                    for (auto& t : temp) noGroup[t] = true;
                    break;
                }
                if (visited[next]) {
                    noGroup[i] = true;
                    break;
                }
                visited[next] = true;
                dfs.push(next);
                temp.push_back(next);
            }
        }
        cout << n - accumulate(group.begin(), group.end(), 0) << '\n';
    }
}
