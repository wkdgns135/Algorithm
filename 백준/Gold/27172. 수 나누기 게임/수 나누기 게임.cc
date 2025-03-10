#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    unordered_map<int, bool> dict;
    vector<int> v1(n);
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
        dict[v1[i]] = true;
        maxVal = max(maxVal, v1[i]);
    }
    vector<int> v2(maxVal + 1);
    for (int i = 1; i <= maxVal; i++)
    {
        if (dict[i])
        {
            for (int j = i + i; j <= maxVal; j += i)
            {
                if (!dict[j])continue;
                 v2[j]--;
                 v2[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v2[v1[i]] << ' ';
    }
}
