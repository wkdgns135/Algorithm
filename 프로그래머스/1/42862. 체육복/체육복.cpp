#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n, 1);
    for(int &i : lost)v[i - 1]--;
    for(int &i : reserve)v[i - 1]++;
    
    for(int i = 0; i < n; i++){
        if(v[i] == 0){
            if(i > 0 && v[i - 1] == 2)v[i]++, v[i - 1]--;
            else if(i < n && v[i + 1] == 2)v[i]++, v[i + 1]--;
        }
        if(v[i] > 0)answer++;
    }
    
    return answer;
}