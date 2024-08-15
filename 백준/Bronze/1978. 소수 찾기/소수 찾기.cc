#include <bits/stdc++.h>

using namespace std;

bool CheckPrime(int n) {
    if (n == 1)return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, answer = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < v.size(); i++)if (CheckPrime(v[i]))answer++;
    cout << answer;
}
