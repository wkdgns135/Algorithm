#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
struct Cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return v[a.first][a.second] > v[b.first][b.second];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int offset[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1 ,0} };
    int index = 1;
    for (n; n != 0; cin >> n) {
        v.clear();
        v.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> mdt(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        pq.push({ 0, 0 });
        mdt[0][0] = v[0][0];
        while (!pq.empty()) {
            int x, y; tie(y, x) = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + offset[i][0];
                int yy = y + offset[i][1];
                if (xx < 0 || xx >= n || yy < 0 || yy >= n || mdt[yy][xx] <= mdt[y][x] + v[yy][xx])continue;
                pq.push({ yy,xx });
                mdt[yy][xx] = mdt[y][x] + v[yy][xx];
            }
        }
        cout << "Problem "<< index++ << ": " << mdt[n - 1][n - 1] << '\n';
    }
}
