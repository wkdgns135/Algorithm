#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = !obstacleGrid[0][0];
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (i == 0 && j == 0 || obstacleGrid[i][j])continue;
                if (j - 1 >= 0 && !obstacleGrid[i][j - 1])dp[i][j] += dp[i][j - 1];
                if (i - 1 >= 0 && !obstacleGrid[i - 1][j])dp[i][j] += dp[i - 1][j];
            }
        }

        return dp[n - 1][m - 1];
    }
};