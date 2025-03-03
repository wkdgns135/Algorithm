#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    long long a, b, g; cin >> a >> b;
    g = gcd(a, b);
    for (int i = 0; i < g; i++)
    {
        cout << "1";
    }
}