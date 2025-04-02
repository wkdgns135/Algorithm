#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c; cin >> a >> b >> c;
    int i, j;
    for (i = b + c, j = a; i >= b; i--, j++)
    {
        if (i % 4 == 0 && j % 3 == 0)
        {
            cout << j / 3 << ' ' << i / 4;
            return 0;
        }
    }
    cout << -1;
}