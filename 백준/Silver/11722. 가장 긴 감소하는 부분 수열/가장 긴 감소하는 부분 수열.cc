#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v;
    while (N--) {
        int i;
        cin >> i;
        auto it = lower_bound(v.begin(), v.end(), i,greater<int>());
        if (it == v.end()) v.push_back(i);
        else v[it - v.begin()] = i;
    }
    cout << v.size() << '\n';
}