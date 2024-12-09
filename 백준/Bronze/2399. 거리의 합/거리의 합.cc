#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer += abs(v[i] - v[j]);
        }
    }
    cout << answer;
}
