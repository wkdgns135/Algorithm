#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, f; cin >> n >> m >> f;
    vector<bool> facts;
    facts.resize(n + 1);
    vector<vector<int>> parties(m);
    vector<set<int>> graph(n + 1);
    for (int i = 0; i < f; i++) {
        int input; cin >> input;
        facts[input] = true;
    }
    for (int i = 0; i < m; i++) {
        int input; cin >> input;
        parties[i].resize(input);
        for (int j = 0; j < input; j++)cin >> parties[i][j];
        for (int j = 0; j < input; j++) {
            for (int k = j + 1; k < input; k++) {
                graph[parties[i][j]].insert(parties[i][k]);
                graph[parties[i][k]].insert(parties[i][j]);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (!facts[i])continue;
        queue<int> bfs;
        bfs.push(i);
        vector<bool> visited(n + 1);
        visited[i] = true;

        while (!bfs.empty()) {
            int node = bfs.front();
            bfs.pop();

            for (auto& next : graph[node]) {
                if (visited[next])continue;
                bfs.push(next);
                visited[next] = true;
                facts[next] = true;
            }
        }
    }

    int answer = 0;
    for (auto& party : parties) {
        if (!any_of(party.begin(), party.end(), [&](int person) {
            return facts[person];
            })) {
            answer++;
        }
    }
    cout << answer;
}
