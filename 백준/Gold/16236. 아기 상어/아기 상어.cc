#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    pair<int, int> pos;
    int offset[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 9) {
                v[i][j] = 0;
                pos = { i, j };
            }
        }
    }
    int size = 2, eat = 0, answer = 0;
    while (true) {
        queue<pair<int, int>> bfs;
        vector<vector<int>> visited(n, vector<int>(n, -1));
        visited[pos.first][pos.second] = 0;
        bfs.push(pos);
        vector<tuple<int, int, int>> fishes;
        while (!bfs.empty()) {
            int x, y; tie(y, x) = bfs.front();
            bfs.pop();
            if (v[y][x] > 0 && v[y][x] < size) {
                if (!fishes.empty()) {
                    if(get<0>(fishes[0]) == visited[y][x])fishes.push_back({visited[y][x], y, x});
                }else fishes.push_back({ visited[y][x], y, x });
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + offset[i][1];
                int yy = y + offset[i][0];
                if (xx >= n || xx < 0 || yy >= n || yy < 0 || v[yy][xx] > size || visited[yy][xx] != -1) continue;
                bfs.push({ yy, xx });
                visited[yy][xx] = visited[y][x] + 1;
            }
        }

        if (fishes.empty())break;
        pair<int, int> fish = { get<1>(fishes[0]), get<2>(fishes[0])};
        for (auto &i : fishes) {
            if (fish.first > get<1>(i))fish = { get<1>(i), get<2>(i) };
            else if (fish.first == get<1>(i) && fish.second > get<2>(i))fish.second = get<2>(i);
        }
        eat++;
        answer += get<0>(fishes[0]);
        v[fish.first][fish.second] = 0;
        pos = fish;
        if (eat == size) {
            size++;
            eat = 0;
        }
    }
    cout << answer;
}
