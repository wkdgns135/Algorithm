#include <bits/stdc++.h>
using namespace std;

int n, maxVal;
vector<vector<int>> v;
vector<pair<int, int>> white, black;
vector<bool> diag1, diag2;

bool CheckPosition(int x, int y) {
    return !diag1[x + y] && !diag2[x - y + (n - 1)];
}

void Place(int x, int y, int state) {
    diag1[x + y] = state;
    diag2[x - y + (n - 1)] = state;
}

void BackTracking(int depth, int count, vector<pair<int, int>>& target) {
    maxVal = max(maxVal, count);

    if (depth >= target.size()) return;
    if (count + (target.size() - depth) <= maxVal) return; // 가지치기

    int x = target[depth].second;
    int y = target[depth].first;

    if (CheckPosition(x, y)) {
        Place(x, y, 1);
        BackTracking(depth + 1, count + 1, target);
        Place(x, y, 0);
    }
    BackTracking(depth + 1, count, target); // 현재 위치를 건너뛰는 경우
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    v.resize(n, vector<int>(n));
    diag1.resize(2 * n - 1, false);
    diag2.resize(2 * n - 1, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input; cin >> input;
            v[i][j] = input;
            if (v[i][j]) {
                if ((i + j) % 2 == 0) white.push_back({ i, j });
                else black.push_back({ i, j });
            }
        }
    }

    int result = 0;
    maxVal = 0;
    BackTracking(0, 0, white);
    result += maxVal;

    maxVal = 0;
    BackTracking(0, 0, black);
    result += maxVal;

    cout << result;
}
