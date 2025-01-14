#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<pair<int, int>>>& graph, vector<vector<bool>>& finish, vector<vector<bool>>& visited, int& cycle) {
    visited[y][x] = true;

    int xx, yy; tie(yy, xx) = graph[y][x];
    if (!visited[yy][xx]) {
        dfs(xx, yy, graph, finish, visited, cycle);
    }
    else if (!finish[yy][xx]) {
        cycle++;
    }
    finish[y][x] = true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>(m));

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            char ch = s[j];
            if (ch == 'U') graph[i][j] = { i - 1, j };
            if (ch == 'D') graph[i][j] = { i + 1, j };
            if (ch == 'L') graph[i][j] = { i, j - 1 };
            if (ch == 'R') graph[i][j] = { i, j + 1 };
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m)), finish(n, vector<bool>(m));
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(j, i, graph, finish, visited, answer);
        }
    }
    cout << answer;
}
