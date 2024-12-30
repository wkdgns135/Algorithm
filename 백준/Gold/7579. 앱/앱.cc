#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> apps(n + 1), costs(n + 1);
    for (int i = 1; i <= n; i++)cin >> apps[i];
    for (int i = 1; i <= n; i++)cin >> costs[i];

    vector<int> dp(10001, 0);
    int minCost = 10001; // 초기 최소 비용

    for (int i = 1; i <= n; i++) {
        int c = costs[i];
        int a = apps[i];
        for (int j = 10000; j >= c; j--) {
            dp[j] = max(dp[j], dp[j - c] + a);
            if (dp[j] >= m) minCost = min(minCost, j);
        }
    }

    cout << minCost << '\n';
}
