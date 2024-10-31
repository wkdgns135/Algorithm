#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> innings;
vector<int> inning;
vector<bool> visited;
int answer = 0;
int CalcInning() {
    int score = 0, batter = 0;
    for (int i = 0; i < innings.size(); i++) {
        int out = 0;
        vector<bool> base(3);
        while(out < 3){
            int bat = innings[i][inning[batter]];
            if (bat == 0) out++;
            else if (bat == 1) {
                if (base[2]) { score++; base[2] = false; }
                if (base[1]) { base[2] = true; base[1] = false; }
                if (base[0]) { base[1] = true; base[0] = false; }
                base[0] = true;
            }
            else if (bat == 2) {
                if (base[2]) { score++; base[2] = false; }
                if (base[1]) { score++; base[1] = false; }
                if (base[0]) { base[2] = true; base[0] = false; }
                base[1] = true;
            }
            else if (bat == 3) {
                if (base[2]) { score++; base[2] = false; }
                if (base[1]) { score++; base[1] = false; }
                if (base[0]) { score++; base[0] = false; }
                base[2] = true;
            }
            else if (bat == 4){
                if (base[2]) { score++; base[2] = false; }
                if (base[1]) { score++; base[1] = false; }
                if (base[0]) { score++; base[0] = false; }
                score++;
            }
            batter = (batter + 1) % 9;
        }
    }
    return score;
}

void BackTracking(int depth) {
    if (depth == 3) {
        BackTracking(depth + 1);
        return;
    }
    if (depth == 9) {
        answer = max(answer, CalcInning());
        return;
    }
    for (int i = 1; i < 9; i++) {
        if (visited[i])continue;
        visited[i] = true;
        inning[depth] = i;
        BackTracking(depth + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    innings.resize(n, vector<int>(9));
    for (int i = 0; i < n; i++)for (int j = 0; j < 9; j++) cin >> innings[i][j];
    inning.resize(9), visited.resize(9);
    BackTracking(0);
    cout << answer;
}
