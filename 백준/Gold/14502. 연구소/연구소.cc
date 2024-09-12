#include<bits/stdc++.h>
using namespace std;

int n, m, answer = 0;
vector<vector<int>> v;
vector<pair<int, int>> virus;

int Count() {
    vector<vector<bool>> visited(n, vector<bool>(m));
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int sum = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visited[i][j] = v[i][j];

    for (auto& pos : virus) {
        stack<pair<int, int>> dfs;
        dfs.push({ pos.first, pos.second });

        while (!dfs.empty()) {
            int x = dfs.top().second;
            int y = dfs.top().first;
            dfs.pop();

            for (int i = 0; i < 4; i++) {
                int xx = x + offset[i][0];
                int yy = y + offset[i][1];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[yy][xx]) {
                    visited[yy][xx] = true;
                    dfs.push({ yy, xx });
                }
            }
        }
    }

    for (auto& i : visited) sum += accumulate(i.begin(), i.end(), 0);
    return n * m - sum;
}

void BackTracking(int depth) {
    if (!depth) {
        answer = max(answer, Count());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!v[i][j]) {
                v[i][j] = 1;
                BackTracking(depth - 1);
                v[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                virus.push_back({ i, j });
                v[i][j] = 1;
            }
        }
    }
    BackTracking(3);

    cout << answer;
}
