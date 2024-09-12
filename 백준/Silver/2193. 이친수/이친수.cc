#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    vector<long long> dp(n + 1, 1);
    for (int i = 3; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n];
}
