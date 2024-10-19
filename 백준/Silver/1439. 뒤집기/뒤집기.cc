#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    char prev = s[0];
    vector<int> v(2);
    s.push_back('2');
    for (int i = 1; i < s.size(); i++) {
        if (prev != s[i]) {
            v[prev - '0']++;
            prev = s[i];
        }
    }
    cout << min(v[0], v[1]);
}
