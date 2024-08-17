#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0 ; i <= discount.size()-10; i++){
        vector<int> v(want.size());
        for(int j = i; j < i + 10; j++){
            for(int k = 0; k < want.size(); k++){
                if(want[k] == discount[j])v[k]++;
            }
        }
        bool flag = true;
        for(int j = 0; j < v.size(); j++){
            if(v[j] < number[j]){
                flag = false;
                break;
            }
        }
        if(flag)answer++;
    }
    
    return answer;
}