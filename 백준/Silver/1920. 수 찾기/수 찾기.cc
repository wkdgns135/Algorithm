#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n;
    unordered_map<int, int> map;
    while(n--){int input; cin >> input; map[input]++;}
    cin >> m;
    while(m--){
        int input; cin >> input; 
        if(map[input])cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}