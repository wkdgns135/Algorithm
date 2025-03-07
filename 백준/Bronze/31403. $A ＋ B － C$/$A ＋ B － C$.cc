#include <bits/stdc++.h>
using namespace std;
#define s(x) stoi(x)
int main()
{
    string a, b, c; cin >> a >> b >> c;
    cout << s(a) + s(b) - s(c) << '\n' << s(a + b) - s(c);
}