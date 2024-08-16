#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    vector<int> v(10001, 1);
    for (int i = 2; i < 10001; i++)v[i] += v[i - 2];
    for (int i = 3; i < 10001; i++)v[i] += v[i - 3];
    for (int i = 0; i < T; i++) {cin >> N;cout << v[N] << "\n";}
    return 0;
}