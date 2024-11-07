#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string cmp = "I";
    int answer = 0;
    for (int i = 0; i < n; i++)cmp += "OI";
    for (int i = 0; i <= m - (n * 2 + 1) ; i++) {
        string temp = s.substr(i, n * 2 + 1);
        if (temp == cmp)answer++;
    }
    cout << answer;
}
