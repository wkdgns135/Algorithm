#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, n, k; cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> answer;
    int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                v[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (v[y][x])continue;
            stack<pair<int, int>> s;
            s.push({ y, x });
            v[y][x] = 1;
            int count = 1;
            while (!s.empty()) {
                auto pos = s.top();
                s.pop();
                for (int i = 0; i < 4; i++) {
                    int xx = pos.second + offset[i][0];
                    int yy = pos.first + offset[i][1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n || v[yy][xx])continue;
                    v[yy][xx] = 1;
                    s.push({ yy,xx });
                    count++;
                }
            }
            answer.push_back(count);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto& i : answer)cout << i << ' ';
}