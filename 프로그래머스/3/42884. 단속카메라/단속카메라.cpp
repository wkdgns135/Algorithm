#include <bits/stdc++.h>
using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 0;
    int range = -INT_MAX;
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
    
    for(int i = 0; i < routes.size(); i++){
        if(routes[i][0] <= range)range = min(routes[i][1], range);
        else{answer++;range = routes[i][1];}
    }
    
    return answer;
}