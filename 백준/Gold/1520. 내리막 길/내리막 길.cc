#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
struct Cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return v[a.first][a.second] < v[b.first][b.second];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> v[i][j];
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, Cmp> pq;
    vector<vector<int>> visited(n, vector<int>(m));
    visited[0][0] = 1;
    pq.push({ 0,0 });
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

    while (!pq.empty()) {
        int x, y; tie(y, x) = pq.top();
        pq.pop();
        if (visited[y][x] > 0 && (x != 0 && y != 0))continue;

        for (int i = 0; i < 4; i++) {
            int xx = offset[i][0] + x;
            int yy = offset[i][1] + y;
            if (xx < 0 || xx >= m || yy < 0 || yy >= n)continue;
            if (v[yy][xx] > v[y][x]) visited[y][x] += visited[yy][xx];
            if (v[yy][xx] < v[y][x]) pq.push({yy,xx});
        }
    }
    cout << visited[n-1][m-1];
}
