#include <bits/stdc++.h>
using namespace std;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int N; // 방향을 바꾼 횟수
    long long T; // 총 걸어간 시간
    cin >> N >> T;

    vector<pair<long long, string>> turns(N);
    for (int i = 0; i < N; i++) {
        cin >> turns[i].first >> turns[i].second;
    }

    long long x = 0, y = 0; // 초기 위치
    int direction = 0; // 초기 방향 (동쪽)

    long long currentTime = 0;
    for (int i = 0; i < N; i++) {
        long long time = turns[i].first;
        string turn = turns[i].second;

        // time - currentTime 동안 현재 방향으로 이동
        long long moveTime = min(time - currentTime, T - currentTime);
        x += dx[direction] * moveTime;
        y += dy[direction] * moveTime;
        currentTime += moveTime;

        // 시간이 T에 도달하면 종료
        if (currentTime >= T) break;

        // 방향 전환
        if (turn == "left") {
            direction = (direction + 1) % 4;
        }
        else if (turn == "right") {
            direction = (direction + 3) % 4; // 오른쪽은 시계 방향 회전
        }
    }

    // 남은 시간 동안 이동
    if (currentTime < T) {
        long long remainingTime = T - currentTime;
        x += dx[direction] * remainingTime;
        y += dy[direction] * remainingTime;
    }

    cout << x << " " << y << endl;

    return 0;
}