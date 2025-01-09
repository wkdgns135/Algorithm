#include <bits/stdc++.h>
using namespace std;

class Shark {
public:
    int x, y;
    int speed;
    int direction;
    int size;
    Shark(int r, int c) {
        cin >> speed >> direction >> size;
        y = r;
        x = c;
    }

    void Move(int r, int c) {
        // 방향에 따른 이동 거리 계산
        int move = speed;
        if (direction == 1 || direction == 2) {
            move %= (2 * (r - 1)); // 상하 이동
        }
        else {
            move %= (2 * (c - 1)); // 좌우 이동
        }

        // 이동 시뮬레이션
        while (move > 0) {
            if (direction == 1) { // 위로 이동
                if (y - move >= 0) {
                    y -= move;
                    move = 0;
                }
                else {
                    move -= y;
                    y = 0;
                    direction = 2; // 방향 반전
                }
            }
            else if (direction == 2) { // 아래로 이동
                if (y + move < r) {
                    y += move;
                    move = 0;
                }
                else {
                    move -= (r - 1 - y);
                    y = r - 1;
                    direction = 1; // 방향 반전
                }
            }
            else if (direction == 3) { // 오른쪽으로 이동
                if (x + move < c) {
                    x += move;
                    move = 0;
                }
                else {
                    move -= (c - 1 - x);
                    x = c - 1;
                    direction = 4; // 방향 반전
                }
            }
            else if (direction == 4) { // 왼쪽으로 이동
                if (x - move >= 0) {
                    x -= move;
                    move = 0;
                }
                else {
                    move -= x;
                    x = 0;
                    direction = 3; // 방향 반전
                }
            }
        }
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int r, c, m; cin >> r >> c >> m;

    vector<vector<Shark*>> sea(r, vector<Shark*>(c, nullptr));
    list<Shark*> sharks;

    // 상어 초기화
    for (int i = 0; i < m; i++) {
        int rr, cc; cin >> rr >> cc;
        rr--, cc--;
        sea[rr][cc] = new Shark(rr, cc);
        sharks.push_back(sea[rr][cc]);
    }

    int answer = 0;

    for (int i = 0; i < c; i++) {
        // 1. 낚시왕이 상어를 잡는다
        for (int j = 0; j < r; j++) {
            if (sea[j][i]) {
                answer += sea[j][i]->size;
                sharks.remove(sea[j][i]);
                delete sea[j][i];
                sea[j][i] = nullptr;
                break;
            }
        }

        // 2. 상어 이동
        vector<vector<Shark*>> new_sea(r, vector<Shark*>(c, nullptr));
        list<Shark*> new_sharks;

        for (auto& shark : sharks) {
            // 이전 위치 저장
            int prev_x = shark->x;
            int prev_y = shark->y;

            // 상어 이동
            shark->Move(r, c);

            // 이동한 위치의 상어 충돌 처리
            Shark* existing = new_sea[shark->y][shark->x];
            if (existing) {
                if (shark->size > existing->size) {
                    new_sharks.remove(existing);
                    delete existing;
                    new_sea[shark->y][shark->x] = shark;
                    new_sharks.push_back(shark);
                }
                else {
                    delete shark;
                }
            }
            else {
                new_sea[shark->y][shark->x] = shark;
                new_sharks.push_back(shark);
            }
        }
        sea = move(new_sea);
        sharks = move(new_sharks);
    }

    cout << answer;
}
