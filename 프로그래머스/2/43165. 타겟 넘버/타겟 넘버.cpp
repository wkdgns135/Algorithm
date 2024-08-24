#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack<pair<int, int>> dfs;
    dfs.push({0, 0});
    
    while(!dfs.empty()){
        int index = dfs.top().first;
        int value = dfs.top().second;
        dfs.pop();
        if(index == numbers.size()){
            if(value == target)answer++;
        }else{
            dfs.push({index + 1, value + numbers[index]});
            dfs.push({index + 1, value - numbers[index]});
        }
    }
    
    return answer;
}