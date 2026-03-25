#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<vector<long long>> dp(2, vector<long long>(500000));
    
    dp[0][0] = sequence[0], dp[1][0] = sequence[0] * -1;
    answer = max(answer, max(dp[0][0], dp[1][0]));
    
    for(int i = 1; i < sequence.size(); i++){
        long long num = sequence[i];
        long long opposite = num * -1;
        
        dp[0][i] = max(dp[1][i - 1] + num, num);
        dp[1][i] = max(dp[0][i - 1] + opposite, opposite);
        
        answer = max(answer, max(dp[0][i], dp[1][i]));
    }
    
    return answer;
}