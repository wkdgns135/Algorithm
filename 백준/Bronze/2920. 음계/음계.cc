#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> v[i];
    }
    // ascending
    for (int i = 0; i < 8; i++)
    {
        if (v[i] != i + 1)break;
        if (i == 7)
        {
            cout << "ascending";
            return 0;
        }
    }
    // descending
    for (int i = 0; i < 8; i++)
    {
        if (v[i] != 8 - i)break;
        if (i == 7)
        {
            cout << "descending";
            return 0;
        }
    }
    cout << "mixed";
}
