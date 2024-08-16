#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v(N + 1, 1); v[1] = 0;
    for (int i = 4; i <= N; i++) v[i] = min({ v[i - 1], i % 2 == 0 ? v[i / 2] : INT_MAX, i % 3 == 0 ? v[i / 3] : INT_MAX}) + 1;
    cout << v[N];
    return 0;
}