#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

int answer = INT_MAX;
vector<vector<int>> v;
vector<int> paper = { 0, 0, 0, 0, 0 };

inline bool CheckGrid() {
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++)if (v[i][j])return false;
    return true;
}

inline int PaperCount() {
    int sum = 0;
    for (int i = 0; i < 5; i++) sum += paper[i] * (i + 1) * (i + 1);
    return sum;
}

inline bool CheckPaper(const vector<vector<int>>& temp, const int x, const int y, const int size) {
    if (y + size > SIZE || x + size > SIZE) return false;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (!temp[i][j]) return false;
        }
    }
    return true;
}

inline void FillPaper(vector<vector<int>>& temp, const int x, const int y, const int size, const int num) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            temp[i][j] = num;
        }
    }
}

void BackTracking(const int depth) {
    if (answer < depth) return;

    if (CheckGrid()) {
        answer = min(answer, depth);
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!v[i][j])continue;
            for (int k = 0; k < 5; k++) {
                if (paper[k] < 5 && CheckPaper(v, j, i, k + 1)) {
                    paper[k]++;
                    FillPaper(v, j, i, k + 1, 0);
                    BackTracking(depth + 1);
                    FillPaper(v, j, i, k + 1, 1);
                    paper[k]--;
                }
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    v = vector<vector<int>>(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) cin >> v[i][j];
    BackTracking(0);
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}