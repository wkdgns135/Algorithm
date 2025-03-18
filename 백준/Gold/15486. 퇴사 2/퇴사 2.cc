#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);

        int index = i + v[i].first;
        if (index <= n)
        {
            dp[index] = max(dp[index], dp[i] + v[i].second);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}