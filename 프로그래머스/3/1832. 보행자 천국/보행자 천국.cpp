#include <vector>
using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int MOD = 20170805;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));
    dp[0][0][0] = 1, dp[1][0][0] = 1;
    
    for(int i = 1; i < m; ++i){
        if(city_map[i][0] == 1) continue;
        dp[1][i][0] = dp[1][i - 1][0];
    }
    
    for(int i = 1; i < n; ++i){
        if(city_map[0][i] == 1) continue;
        dp[0][0][i] = dp[0][0][i - 1];
    }
    
    for(int y = 1; y < m; ++y){
        for(int x = 1; x < n; ++x){
            if(city_map[y][x] == 1) continue;
            
            if(city_map[y - 1][x] == 2) dp[1][y][x] = dp[1][y - 1][x];
            else dp[1][y][x] = dp[0][y - 1][x] + dp[1][y - 1][x];
            
            if(city_map[y][x - 1] == 2) dp[0][y][x] = dp[0][y][x - 1];
            else dp[0][y][x] = dp[0][y][x - 1] + dp[1][y][x - 1];
            
            dp[0][y][x] %= MOD;
            dp[1][y][x] %= MOD;
        }
    }
    
    return (dp[0][m - 1][n - 1] + dp[1][m - 1][n - 1]) % MOD;
}