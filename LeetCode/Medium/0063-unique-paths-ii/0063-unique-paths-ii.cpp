#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        obstacleGrid[0][0] = !obstacleGrid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)continue;
                if(obstacleGrid[i][j]){obstacleGrid[i][j] = 0; continue;}
                if (j - 1 >= 0)obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                if (i - 1 >= 0)obstacleGrid[i][j] += obstacleGrid[i - 1][j];
            }
        }
        return obstacleGrid.back().back();
    }
};