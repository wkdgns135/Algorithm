#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int answer = 1;
    char prev = s[0];
    for (int i = 1; i < s.size(); prev = s[i], i++) {
        if (prev >= s[i])answer++;
    }
    cout << answer;
}
