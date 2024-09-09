#include<bits/stdc++.h>
using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    vector<vector<int>> dp(onboard.size(), vector<int>(101, 99999));
    temperature += 10, t1 += 10, t2 += 10;
    int minT = min(t1, t2), maxT = max(t1, t2);
    int last = 0;
    for (int i = onboard.size() - 1; i >= 0; i--)if (onboard[i]) { last = i; break; }
    dp[0][temperature] = 0;

    for (int i = 1; i <= last; i++){
        pair<int, int> range;
        if (onboard[i]) range = { minT, maxT };
        else range = {0, 100};

        for (int j = range.first; j <= range.second; j++) {
            if (j == temperature) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
                if(j > 0) dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                if(j < 100) dp[i][j] = min(dp[i - 1][j + 1], dp[i][j]);
            }
            else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + b);
                if (j < temperature) {
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    if (j < 100) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a);
                }
                else {
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a);
                    if (j < 100) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }
            }
        }
    }

    return *min_element(dp[last].begin() + minT, dp[last].begin() + maxT + 1);
}