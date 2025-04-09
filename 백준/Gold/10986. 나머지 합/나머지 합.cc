#include <bits/stdc++.h>
using namespace std;



int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    unordered_map<int, int> dict;
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0, sum = 0; i < n; i++)
    {
        sum += v[i];
        sum %= m;
        dict[sum]++;
        if (sum == 0)answer++;
    }
    
    for (const auto& ele : dict)
    {
        if (ele.second > 1)
        {
            answer += static_cast<long long>(ele.second - 1) * ele.second / 2;
        }
    }
    cout << answer;
}
