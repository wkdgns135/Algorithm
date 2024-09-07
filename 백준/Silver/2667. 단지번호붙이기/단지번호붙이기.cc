#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<string> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> answer;
    int offset[4][2]{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != '1')continue;
            stack<pair<int, int>> dfs;
            dfs.push({ i, j });
            v[i][j] = '0';

            int count = 0;
            while (!dfs.empty()) {
                pair<int, int> pos = dfs.top();
                dfs.pop();
                count++;
                for (int k = 0; k < 4; k++) {
                    int xx = pos.second + offset[k][0];
                    int yy = pos.first + offset[k][1];

                    if (xx >= 0 && xx < n && yy >= 0 && yy < n && v[yy][xx] == '1') {
                        v[yy][xx] = '0';
                        dfs.push({ yy , xx});
                    }
                }
            }
            answer.push_back(count);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int i : answer)cout << i << '\n';
}