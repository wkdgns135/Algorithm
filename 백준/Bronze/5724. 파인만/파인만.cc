#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    vector<int> dp(101, 1);
    for (int i = 2; i < 101; i++) {dp[i] = dp[i - 1] + i * i;}
    cin >> N;
    while (N) { cout << dp[N] << '\n'; cin >> N;}
}