#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<int> v(9);
    for (int i = 0; i < 9; i++)cin >> v[i];
    cout << *max_element(v.begin(), v.end()) << '\n';
    cout << max_element(v.begin(), v.end()) - v.begin() + 1;
}