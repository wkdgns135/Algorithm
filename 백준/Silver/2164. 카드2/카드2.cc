#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);         
    int n; cin >> n;
    deque<int> dq(n);
    for(int i = 1; i <= n; i++)dq[i-1] = i;
    while(dq.size() > 1){
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    cout << dq.front();
}