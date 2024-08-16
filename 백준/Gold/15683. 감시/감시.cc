#include <bits/stdc++.h>
#define PI 3.1415926535

using namespace std;

int N, M, answer = INT_MAX;

class CCTV {
    int x, y;
    vector<vector<int>> directions;
public :
    int rotate = 0;
    void Rotate() {
        double radian = 90 * (3.1415926535 / 180);
        for (int i = 0; i < directions.size(); i++) {
            int x = directions[i][1] * cos(radian) - directions[i][0] * sin(radian);
            int y = directions[i][1] * sin(radian) + directions[i][0] * cos(radian);
            directions[i][1] = x;
            directions[i][0] = y;
        }
    }

    void FindArea(vector<vector<int>>& map) {
        for (auto& direction : directions) {
            int xx = x, yy = y;
            while (true) {
                xx += direction[1];
                yy += direction[0];
                if (xx < 0 || yy < 0 || xx >= M || yy >= N || map[yy][xx] == 6) break;
                if (map[yy][xx] == 0) map[yy][xx] = 9;
            }
        }
    }

    CCTV(int type, int x, int y) {
        this->x = x;
        this->y = y;
        switch (type)
        {
        case 1:
            rotate = 4;
            directions.push_back({ 0, 1 });
            break;
        case 2:
            rotate = 2;
            directions.push_back({ 0, 1 });
            directions.push_back({ 0, -1 });
            break;
        case 3:
            rotate = 4;
            directions.push_back({ 0, 1 });
            directions.push_back({ 1, 0 });
            break;
        case 4:
            rotate = 4;
            directions.push_back({ 0, 1 });
            directions.push_back({ 1, 0 });
            directions.push_back({ 0, -1 });
            break;
        case 5:
            rotate = 1;
            directions.push_back({ 0, 1 });
            directions.push_back({ 1, 0 });
            directions.push_back({ 0, -1 });
            directions.push_back({ -1, 0 });
            break;
        }
    }
};

void ClearMap(vector<vector<int>>& map) {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (map[i][j] == 9)map[i][j] = 0;
}

int CheckArea(vector<vector<int>>& map) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 0)sum++;
    return sum;
}

void BackTracking(vector<vector<int>> map, vector<CCTV> &cctv, int n) {
    if (n == cctv.size()) { 
        answer = min(answer, CheckArea(map));
        return;
    }
    
    for (int i = 0; i < cctv[n].rotate; i++) {
        vector<vector<int>> newMap(map);
        cctv[n].FindArea(newMap);
        BackTracking(newMap, cctv, n + 1);
        cctv[n].Rotate();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    vector<CCTV> cctv;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6)cctv.push_back(CCTV(map[i][j], j, i));
        }
    }

    BackTracking(map, cctv, 0);
    cout << answer;
    return 0;
}