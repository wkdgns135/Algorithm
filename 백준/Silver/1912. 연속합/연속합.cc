#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> dp(n);
    dp[0] = v[0];

    for (int i = 1; i < n; i++) dp[i] = max(v[i], dp[i - 1] + v[i]);

    cout << *max_element(dp.begin(), dp.end());
}
