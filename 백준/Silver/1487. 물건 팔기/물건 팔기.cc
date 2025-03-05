#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    unordered_map<int, vector<int>> dict;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        dict[a].push_back(b);
    }

    int maxVal = 0, answer = 0;
    for (const auto &i : dict)
    {
        int sum = 0;
        for (const auto &j : dict)
        {
            for (const auto &k : j.second)
            {
                if (j.first >= i.first && i.first - k > 0)sum += i.first - k;
            }
        }
        if (maxVal < sum)
        {
            answer = i.first;
            maxVal = sum;
        }
        else if (maxVal == sum)
        {
            if (answer > i.first)answer = i.first;
        }
    }
    cout << answer;
}