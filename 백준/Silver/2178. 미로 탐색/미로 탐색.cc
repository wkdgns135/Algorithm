#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n);
    queue<pair<int, int>> bfs; bfs.push({ 0,0 });
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++)v[i].push_back(s[j] - '0');
    }

    while (!bfs.empty()) {
        pair<int, int> pos = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int xx = pos.second + offset[i][0];
            int yy = pos.first + offset[i][1];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
                if (v[yy][xx] == 1) {
                    v[yy][xx] = v[pos.first][pos.second] + 1 ;
                    bfs.push({ yy, xx });
                }
            }
        }
    }
    cout << v[n - 1][m - 1];
}