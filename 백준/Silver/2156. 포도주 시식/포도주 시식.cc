#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(10001), dp(10001); for (int i = 0; i < n; i++) cin >> v[i];
    dp[0] = v[0], dp[1] = v[0] + v[1], dp[2] = v[2] + max(v[0], v[1]), dp[3] = v[3] + max(dp[1], dp[0] + v[2]);
    int answer = *max_element(dp.begin(), dp.begin() + 4);
    for (int i = 4; i < n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + v[i - 1]);
        dp[i] = max(dp[i], dp[i - 4] + v[i - 1]);
        dp[i] += v[i];
        if (dp[i] > answer)answer = dp[i];
    }
    cout << answer;
}
