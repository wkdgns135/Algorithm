#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = 4;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << accumulate(v.begin() + j, v.begin() + i, 0) << ' ';
        for (int j = i; j < n; j++)
            cout << accumulate(v.begin() + i, v.begin() + j, 0) << ' ';
        cout << accumulate(v.begin() + i, v.begin() + n, 0);
        cout << '\n';
    }
}
