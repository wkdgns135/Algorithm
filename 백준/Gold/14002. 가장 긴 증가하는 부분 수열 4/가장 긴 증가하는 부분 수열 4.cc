#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> dp(n);
    vector<int> pre(n, -1);

    for (int i = 0; i < n; i++) cin >> v[i];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (dp[j] > dp[i]) pre[i] = j;
                dp[i] = max(dp[j], dp[i]);
            }
        }
        dp[i]++;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    int index = max_element(dp.begin(), dp.end()) - dp.begin();
    stack<int> s;
    while (index != -1) { s.push(index); index = pre[index]; };
    while (!s.empty()) { cout << v[s.top()] << ' '; s.pop(); }
}