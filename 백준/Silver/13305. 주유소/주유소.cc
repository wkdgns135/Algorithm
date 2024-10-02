#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> costs(n), roads(n - 1), dp(n);
    for (int i = 0; i < n - 1; i++) cin >> roads[i];
    for (int i = 0; i < n; i++) cin >> costs[i];
    int minVal = costs[0];
    for (int i = 1; i < n; i++) {
        dp[i] = roads[i - 1] * minVal + dp[i - 1];
        if (costs[i] < minVal) minVal = costs[i];
    }
    cout << dp[n - 1];
}
