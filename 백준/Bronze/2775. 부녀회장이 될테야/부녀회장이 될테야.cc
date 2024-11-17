#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    vector<vector<int>> v(15, vector<int>(15));
    for (int i = 1; i <= 14; i++) v[0][i] = i;
    for (int i = 1; i <= 14; i++) 
        for (int j = 1; j <= 14; j++)
            v[i][j] = v[i - 1][j] + v[i][j - 1];
   
    while (t--) {
        int k, n; cin >> k >> n;
        cout << v[k][n] << '\n';
    }
}