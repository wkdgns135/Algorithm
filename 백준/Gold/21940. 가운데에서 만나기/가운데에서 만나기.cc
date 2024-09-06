#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, c; cin >> n >> m;
    vector<vector<int>> mdt(n, vector<int>(n, INT_MAX / 2));

    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        mdt[a][b] = c;
    }

    cin >> c; 
    vector<int> v(c);
    for (int i = 0; i < c; i++) { cin >> v[i]; v[i]--; }

    for (int i = 0; i < n; i++)mdt[i][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mdt[j][k] = min(mdt[i][k] + mdt[j][i], mdt[j][k]);
            }
        }
    }

    vector<pair<int,int>> maxVals;

    for (int i = 0; i < n; i++) {
        int maxVal = 0;
        for (int j = 0; j < c; j++) {
            maxVal = max(maxVal, mdt[i][v[j]] + mdt[v[j]][i]);
        }
        maxVals.push_back({maxVal, i});
    }

    sort(maxVals.begin(), maxVals.end());
    
    cout << maxVals[0].second + 1 << ' ';
    for (int i = 1; i < n; i++) {
        if (maxVals[0].first != maxVals[i].first)break;
        cout << maxVals[i].second + 1 << ' ';
    }
}