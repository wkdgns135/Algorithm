#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    vector<float> v(9);
    for (char& c : str) {
        int n = c - '0';
        if (n == 9 || n == 6)v[6] += 0.5;
        else v[n]++;
    }
    v[6] = floor(v[6] + 0.5);
    cout << *max_element(v.begin(), v.end());
}
