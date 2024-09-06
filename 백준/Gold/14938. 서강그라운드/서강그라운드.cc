#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, r; cin >> n >> m >> r;
    vector<int> v(n);
    vector<vector<int>> mdt(n, vector<int>(n, INT_MAX / 2));

    for (int i = 0; i < n; i++) cin >> v[i];

    while (r--) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        mdt[a][b] = c;
        mdt[b][a] = c;
    }

    for (int i = 0; i < n; i++)mdt[i][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mdt[j][k] = min(mdt[i][k] + mdt[j][i], mdt[j][k]);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (mdt[i][j] <= m)sum += v[j];
        }
        answer = max(sum, answer);
    }
    cout << answer;
}