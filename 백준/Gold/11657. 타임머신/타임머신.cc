#include <bits/stdc++.h>
using namespace std;

void bf(int start, int n, int m, vector<tuple<int,int,int>> &edges) {
    vector<long long> mdt(n + 1, 1e9);
    mdt[start] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int s = get<0>(edges[j]);
            int e = get<1>(edges[j]);
            int t = get<2>(edges[j]);

            if (mdt[s] == 1e9)continue;
            if (mdt[e] > mdt[s] + t) {
                mdt[e] = mdt[s] + t;

                if (i == n) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << (mdt[i] == 1e9 ? -1 : mdt[i]) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, e, t;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        edges.push_back({ s, e, t });
    }
    bf(1, n, m, edges);
}
