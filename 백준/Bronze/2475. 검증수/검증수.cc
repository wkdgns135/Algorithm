#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v(5);
    for(int i = 0; i < 5; i++){
        cin >> v[i];
        v[i] *= v[i];
    }
    cout << accumulate(v.begin(), v.end(), 0) % 10 << '\n';
}