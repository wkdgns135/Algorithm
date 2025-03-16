#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c; cin >> a >> b >> c;
    vector<int> v(10);
    for (const char &c : to_string(a * b * c))
    {
        v[c - '0']++;
    }
    for (int i = 0; i <= 9; i++)
    {
        cout << v[i] << '\n';
    }
}