#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    if(n < 3) return *max_element(sticker.begin(), sticker.end());
    
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = sticker[0], dp[0][1] = sticker[1], dp[1][1] = sticker[1];
    dp[0][2] = dp[0][0] + sticker[2], dp[1][2] = sticker[2];
    
    for(int i = 3; i < n; i++){
        dp[0][i] = max(dp[0][i - 2], dp[0][i - 3]) + sticker[i];
        dp[1][i] = max(dp[1][i - 2], dp[1][i - 3]) + sticker[i];
    }
    
    return max(max(dp[0][n - 2], dp[0][n - 3]), max(dp[1][n - 1], dp[1][n - 2]));
}