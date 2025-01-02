#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF; // 갈 수 없는 경우를 무한대로 설정
            }
        }
    }

    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));
    dp[1][0] = 0; // 시작점 초기화

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u))) continue; // 도시 u가 포함되지 않으면 건너뜀
            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue; // 도시 v가 이미 방문되었으면 건너뜀
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    long long result = INF;
    for (int i = 1; i < n; ++i) {
        result = min(result, dp[(1 << n) - 1][i] + cost[i][0]);
    }

    cout << result << endl;
}