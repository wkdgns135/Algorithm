#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool pillar[101][101];
bool beam[101][101];

bool canPillar(int x, int y) {
    if (y == 0) return true;
    if (pillar[y - 1][x]) return true;
    if (x > 0 && beam[y][x - 1]) return true;
    if (beam[y][x]) return true;
    return false;
}

bool canBeam(int x, int y, int n) {
    if (y > 0 && pillar[y - 1][x]) return true;
    if (y > 0 && x + 1 <= n && pillar[y - 1][x + 1]) return true;
    if (x > 0 && x + 1 < n && beam[y][x - 1] && beam[y][x + 1]) return true;
    return false;
}

bool isValid(int n) {
    for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= n; x++) {
            if (pillar[y][x] && !canPillar(x, y)) return false;
            if (beam[y][x] && !canBeam(x, y, n)) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (const auto& cmd : build_frame) {
        int x = cmd[0];
        int y = cmd[1];
        int a = cmd[2];
        int b = cmd[3];

        if (a == 0) { // 기둥
            if (b == 1) { // 설치
                pillar[y][x] = true;
                if (!isValid(n)) pillar[y][x] = false;
            } else { // 삭제
                pillar[y][x] = false;
                if (!isValid(n)) pillar[y][x] = true;
            }
        } else { // 보
            if (b == 1) { // 설치
                beam[y][x] = true;
                if (!isValid(n)) beam[y][x] = false;
            } else { // 삭제
                beam[y][x] = false;
                if (!isValid(n)) beam[y][x] = true;
            }
        }
    }

    vector<vector<int>> answer;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (pillar[y][x]) answer.push_back({x, y, 0});
            if (beam[y][x]) answer.push_back({x, y, 1});
        }
    }

    return answer;
}