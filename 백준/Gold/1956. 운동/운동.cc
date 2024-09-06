#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, e; cin >> v >> e;
    vector<vector<long long>> mdt(v, vector<long long>(v, INT_MAX));

    while (e--) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        mdt[a][b] = c;
    }

    for (int i = 0; i < v; i++)mdt[i][i] = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int k = 0; k < v; k++) {
                mdt[j][k] = min(mdt[j][k], mdt[i][k] + mdt[j][i]);
            }
        }
    }

    long long answer = INT_MAX;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j)continue;
            if (mdt[i][j] == INT_MAX || mdt[j][j] == INT_MAX)continue;
            answer = min(answer, mdt[i][j] + mdt[j][i]);
        }
    }
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}