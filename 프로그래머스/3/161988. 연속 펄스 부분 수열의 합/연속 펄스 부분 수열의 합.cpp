#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    long long prev = 0, prev_opp = 0;
    for(int i = 0; i < sequence.size(); i++){
        long long num = sequence[i];
        
        long long curr = max(prev_opp + num, num);
        long long curr_opp = max(prev - num, -num);
        
        answer = max(answer, max(curr, curr_opp));
        
        prev = curr;
        prev_opp = curr_opp;
    }
    
    return answer;
}