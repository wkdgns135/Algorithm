#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isCrossable(vector<int> &stones, int k, int n){
    int count = 0;
    for(int stone : stones){
        if(stone - n <= 0)count++;
        else count = 0;
        
        if(count == k)return false;
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 0, right = *max_element(stones.begin(), stones.end());
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(isCrossable(stones, k, mid)) left = mid + 1;
        else right = mid - 1;
    }
    
    return left;
}