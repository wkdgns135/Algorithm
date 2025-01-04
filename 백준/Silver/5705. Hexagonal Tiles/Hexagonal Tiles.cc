#include <bits/stdc++.h>
using namespace std;
int main() {
    int i;
    vector<int> dp(41 , 1);
    for (i = 2; i < 41; i++)  dp[i] = dp[i - 1] + dp[i - 2];
    cin >> i;
    for (i; i; cin >> i) cout << dp[i] << '\n';
}
