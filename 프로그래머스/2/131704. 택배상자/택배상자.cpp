#include <stack>
#include <vector>
#include <iterator>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub;
    auto it = order.begin();
    
    for(int i = 1; i <= order.size(); i++){
        if(i == *it){
            answer++;
            it++;
        }else{
            sub.push(i);
        }
        while(!sub.empty() && sub.top() == *it){
            sub.pop();
            it++;
            answer++;
        }
    }
    
    return answer;
}