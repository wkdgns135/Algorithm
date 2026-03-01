#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer(numbers.size());
    
    for(int i = 0; i < numbers.size(); i++){
        answer[i] = numbers[i] + 1;
        if(__builtin_popcountll(answer[i] ^ numbers[i]) > 2){
            answer[i] += (numbers[i] ^ answer[i]) >> 2;
        }
    }
    
    return answer;
}