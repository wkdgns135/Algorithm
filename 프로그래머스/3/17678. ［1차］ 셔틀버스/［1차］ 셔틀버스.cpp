#include <bits/stdc++.h>
using namespace std;

int S2I(string str){
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 4));
}
string I2S(int n){
    string min = "";
    string hour = "";
    min = to_string(n % 60);
    if(n % 60 < 10) min = '0' + min;
    hour = to_string(n / 60);
    if(n / 60 < 10) hour = '0' + hour;
    return hour + ':' + min;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int t0900 = S2I("09:00");
    priority_queue<int, vector<int>, greater<int>> q;
    for(string str : timetable)q.push(S2I(str));

    for(int i = t0900; i < t0900 + n * t; i+= t){
        int count = 0;
        if(i == t0900 + (n - 1) * t){
            if(q.empty())return I2S(i);
            count = 0;
            while(!q.empty()){
                if(count == m - 1){
                    return q.top() - 1 > i ? I2S(i) : I2S(q.top() - 1);
                }
                q.pop();
                count++;
            }
            return I2S(i);
        }
        while(!q.empty()){
            if(q.top() > i || count == m)break;
            if(q.top() <= i){
                q.pop();
                count++;
            }
        }
    }
}