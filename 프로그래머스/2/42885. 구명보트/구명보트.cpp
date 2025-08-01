#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(), people.rend());
    
    int left = 0, right = people.size() - 1;
    
    while(left < right){
        if(people[left] + people[right] > limit){
            left++;
            answer++;
        }else{
            left++;
            right--;
            answer++;
        }
    }
    if(left == right)answer++;
    return answer;
}