#include<bits/stdc++.h>
using namespace std;
int n, answer = INT_MAX;
vector<vector<int>> v;
vector<int> team1;
int Calc() {
    vector<bool> team(n);
    for (int i = 0; i < n / 2; i++)team[team1[i]] = true;
    vector<int> team2;
    for (int i = 0; i < n; i++) if (!team[i])team2.push_back(i);
    
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j)continue;
            t1 += v[team1[i]][team1[j]];
            t2 += v[team2[i]][team2[j]];
        }
    }

    return abs(t1 - t2);
}

void Bt(int depth, int index) {
    if (depth == n / 2) {
        answer = min(answer, Calc());
        return;
    }
    
    for (int i = index; i < n; i++) {
        team1[depth] = i;
        Bt(depth + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v = vector<vector<int>>(n, vector<int>(n));
    team1 = vector<int> (n / 2);
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> v[i][j];

    Bt(1, 1);
    cout << answer;
}
