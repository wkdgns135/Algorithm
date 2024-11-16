#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += (s[i] - 'a' + 1) * pow(31, i);
        answer %= 1234567891;
    }
    cout << answer;
}