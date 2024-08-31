#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    dp[0] = v[0];

    for (int i = 1; i < n; i++) {
        vector<int> temp;
        for (int j = i - 1; j >= 0; j--) {
            if (v[j] < v[i]) temp.push_back(dp[j]);
        }
        if (!temp.empty())dp[i] = v[i] + *max_element(temp.begin(), temp.end());
        else dp[i] += v[i];
    }
    cout << *max_element(dp.begin(), dp.end());
}