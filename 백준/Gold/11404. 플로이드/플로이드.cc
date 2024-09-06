#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> mdt(n, vector<int>(n, INT_MAX / 2));

    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        mdt[a][b] = min(c, mdt[a][b]);
    }

    for (int i = 0; i < n; i++)mdt[i][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mdt[j][k] = min(mdt[i][k] + mdt[j][i], mdt[j][k]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mdt[i][j] == INT_MAX / 2) cout << 0 << ' ';
            else cout << mdt[i][j] << ' ';
        }
        cout << '\n';
    }
}