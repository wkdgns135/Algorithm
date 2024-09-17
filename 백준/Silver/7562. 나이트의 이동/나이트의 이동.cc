#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int offset[8][2] = { {2,1},{1,2},{-2,-1},{-1,-2},{2,-1},{1,-2},{-2,1},{-1,2} };
    while (t--) {
        int l; cin >> l;
        vector<vector<int>> v(l, vector<int>(l, INT_MAX));
        pair<int, int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        queue<pair<int, int>> bfs;
        bfs.push(start);
        v[start.first][start.second] = 0;

        while (!bfs.empty() && !(bfs.front() == end)) {
            auto pos = bfs.front();
            int value = v[pos.first][pos.second];
            bfs.pop();
            
            for (int i = 0; i < 8; i++) {
                int x = pos.second + offset[i][0];
                int y = pos.first + offset[i][1];

                if (x >= 0 && x < l && y >= 0 && y < l && v[y][x] > value + 1) {
                    v[y][x] = value + 1;
                    bfs.push({ y,x });
                }
            }
        }
        cout << v[end.first][end.second] << '\n';
    }
}