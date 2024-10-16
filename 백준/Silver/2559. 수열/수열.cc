#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int sum = accumulate(v.begin(), v.begin() + k, 0);
    int answer = sum;
    for (int i = k; i < n; i++) {
        sum += v[i] - v[i - k];
        answer = max(answer, sum);
    }
    cout << answer;
}
