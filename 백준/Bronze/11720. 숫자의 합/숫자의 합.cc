#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    n = 0;
    for (char c : s)n += c - '0';
    cout << n;
}