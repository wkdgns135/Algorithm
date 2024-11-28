#include <bits/stdc++.h>
using namespace std;


bool bf(int start, int n, int m, vector<tuple<int,int,int>> &edges) {
    vector<int> mdt(n + 1, 1e9);
    mdt[start] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int s = get<0>(edges[j]);
            int e = get<1>(edges[j]);
            int t = get<2>(edges[j]);

            if (mdt[e] > mdt[s] + t) {
                mdt[e] = mdt[s] + t;

                if (i == n)return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc, n, m, w, s, e, t; cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            edges.push_back({ s, e, t });
            edges.push_back({ e, s, t });
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            edges.push_back({ s, e, -t });
        }
        cout << (bf(1, n, m * 2 + w, edges) ? "YES" : "NO") << '\n';
    }
}
