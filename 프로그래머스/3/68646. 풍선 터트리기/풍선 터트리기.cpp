#include <climits>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    int answer = min(2, n);
    vector<int> v1(n), v2(n);
    pair<int,int> minPair = {INT_MAX, INT_MAX};  
    for(int i = 0; i < n; i++){
        if(minPair.first > a[i]){
            minPair.second = minPair.first;
            minPair.first = a[i];
        }else if(minPair.second > a[i]) {
            minPair.second = a[i];
            v1[i]++;
        }else v1[i] += 2;
    }
    
    minPair = {INT_MAX, INT_MAX};
    for(int i = n - 1; i >= 0; i--){
        if(minPair.first > a[i]){
            minPair.second = minPair.first;
            minPair.first = a[i];
        }else if(minPair.second > a[i]){
            minPair.second = a[i];
            v2[i]++;
        }else v2[i] += 2;
    }
    
    for(int i = 1; i < n - 1; i++) {
        if(!v1[i] || !v2[i]) answer++;
        else if(v1[i] + v2[i] == 1) answer++;
    }
    
    return answer;
}