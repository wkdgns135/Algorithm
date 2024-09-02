#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b, answer = ""; cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    vector<int> pre(b.size(), -1);

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    
    int x = b.size(), y = a.size();
    cout << dp[y][x];
    if (!dp[y][x]) return 0;

    while (dp[y][x]) {
        if(dp[y][x] == dp[y][x - 1]) x--;
        else if(dp[y][x] == dp[y - 1][x])y--;
        else { answer += b[x - 1]; x--, y--; }
    }

    reverse(answer.begin(), answer.end());
    cout << '\n' << answer;
}
