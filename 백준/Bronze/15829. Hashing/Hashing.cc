#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    const int MOD = 1234567891;
    const int BASE = 31;
    long long answer = 0;
    long long power = 1; // 31^i 값을 저장할 변수

    for (int i = 0; i < n; i++) {
        answer = (answer + (s[i] - 'a' + 1) * power) % MOD;
        power = (power * BASE) % MOD; // 매번 31^i를 갱신
    }
    cout << answer;
}