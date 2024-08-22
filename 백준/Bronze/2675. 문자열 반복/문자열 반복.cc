#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) for (int j = 0; j < n; j++) cout << s[i];
        cout << '\n';
    }
}