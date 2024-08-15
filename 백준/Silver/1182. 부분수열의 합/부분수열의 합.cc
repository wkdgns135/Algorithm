#include <bits/stdc++.h>
using namespace std;

int N, S, answer;

void BackTracking(vector<int> v, int n, int sum) {
    if (n == N) { if (sum == S)answer++; return; }
    BackTracking(v, n + 1, sum);
    BackTracking(v, n + 1, sum + v[n]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; i++)cin >> v[i];
    BackTracking(v, 0, 0);
    cout << (S == 0 ? answer - 1 : answer);
}
