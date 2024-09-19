#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<vector<int>> vv;
int r, c, answer = 0;
int offset[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<bool> dict;

void BackTracking(const int x, const int y) {
    answer = max(answer, vv[y][x]);
    for (int i = 0; i < 4; i++) {
        int xx = x + offset[i][0];
        int yy = y + offset[i][1];
        if (xx >= 0 && xx < c && yy >= 0 && yy < r && !dict[v[yy][xx] - 'A'] && vv[yy][xx] < vv[y][x] + 1) {
            dict[v[yy][xx] - 'A'] = true;
            vv[yy][xx] = vv[y][x] + 1;
            BackTracking( xx, yy);
            vv[yy][xx] = 0;
            dict[v[yy][xx] - 'A'] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    v = vector<string>(r); for (int i = 0; i < r; i++) cin >> v[i];
    vv = vector<vector<int>>(r, vector<int>(c));
    dict = vector<bool>(26);
    dict[v[0][0] - 'A'] = true, vv[0][0] = 1;
    BackTracking(0, 0);
    cout << answer;
}