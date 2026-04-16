#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    int size = 0;
    for(const auto &score : scores) {
        size = max(size, score[0]);
    }
    vector<int> v(size + 1);
    
    for(int i = 1; i < scores.size(); i++){
        int index = max(scores[i][0] - 1, 0);
        if(v[index] < scores[i][1]){
            v[index] = scores[i][1]; 
        }
    }
    
    int prev = v[v.size() - 1];
    for(int i = v.size() - 2; i > 0; i--){
        if(prev > v[i]){
            v[i] = prev;
        }else if(prev < v[i]){
            prev = v[i];
        }
    }
    
    if(scores[0][1] < v[scores[0][0]]) {
        return -1;
    }
    
    sort(scores.begin() + 1, scores.end(), [](const vector<int> &a, const vector<int> &b){
        return a[0] + a[1] > b[0] + b[1];
    });
        
    int count = 1;
    int target = scores[0][0] + scores[0][1];
    for(int i = 1; i < scores.size(); i++){
        if(scores[i][1] < v[scores[i][0]]) continue;
        int sum = scores[i][0] + scores[i][1];
        if(sum > target){
            answer += count;
            count = 1;
        }else if(sum == target){
            count++;
        }
    }
    
    return answer;
}