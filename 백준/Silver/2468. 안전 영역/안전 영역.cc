#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, limit = 0, answer = 1; cin >> n;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            limit = max(limit, v[i][j]);
        }
    }

    for (int rain = 1; rain <= limit; rain++) {
        vector<vector<bool>> visited(n, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] <= rain)visited[i][j] = true;
                if (visited[i][j])continue;
                count++;

                stack<pair<int, int>> s;
                s.push({ i,j });
                visited[i][j] = true;

                while (!s.empty()) {
                    auto pos = s.top();
                    s.pop();
                    for (int k = 0; k < 4; k++) {
                        int x = pos.second + offset[k][0];
                        int y = pos.first + offset[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < n && !visited[y][x] && v[y][x] > rain) {
                           visited[y][x] = true;
                           s.push({ y,x });
                        }
                    }
                }
                answer = max(answer, count);
            }
        }
    }

    cout << answer;
}
