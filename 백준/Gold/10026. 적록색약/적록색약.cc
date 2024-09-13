#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;

bool CheckRGB(vector<vector<bool>>&visited, int x, int y, char c) {
    if (x >= 0 && x < n && y >= 0 && y < n && !visited[y][x] && c == v[y][x])return true;
    return false;
}

bool CheckRG_B(vector<vector<bool>>& visited, int x, int y, char c) {
    if (x < 0 || x >= n || y < 0 || y >= n || visited[y][x])return false;
    if ((c == 'R' && v[y][x] == 'G') || (c == 'G' && v[y][x] == 'R'))return true;
    if (c != v[y][x])return false;
    return true;
}

int dfs(bool (*Check)(vector<vector<bool>>&, int, int, char)) {
    vector<vector<bool>> visited(n, vector<bool>(n));
    int offset[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])continue;
            visited[i][j] = true;
            count++;
            stack<pair<int, int>> s;
            s.push({ i ,j });
            while (!s.empty()) {
                auto pos = s.top();
                char c = v[pos.first][pos.second];
                s.pop();

                for (int k = 0; k < 4; k++) {
                    int x = pos.second + offset[k][0];
                    int y = pos.first + offset[k][1];

                    if (Check(visited, x, y, c)) {
                        visited[y][x] = true;
                        s.push({ y,x });
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v = vector<string>(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << dfs(CheckRGB) << '\n';
    cout << dfs(CheckRG_B) << '\n';
}
