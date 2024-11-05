#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1));
    // 그래프 초기화: 자기 자신으로 가는 경로는 true
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = (i == j);
        }
    }

    // 비교 결과 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true; // a번 학생이 b번 학생보다 키가 작다
    }

    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) {
                count++;
            }
        }
        if (count == n) { // 모든 학생과 비교가 가능하다면
            answer++;
        }
    }

    cout << answer << endl;
}