#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k+1));
    vector<Item> v(n + 1);

    for (int i = 1; i <= n; i++) {
        int weight, value; cin >> weight >> value;
        v[i] = { weight, value };
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < v[i].weight) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j -v[i].weight] + v[i].value);
        }
    }
    cout << dp[n][k];
}
