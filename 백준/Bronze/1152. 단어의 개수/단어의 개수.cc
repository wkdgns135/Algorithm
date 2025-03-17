#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str;
    getline(cin, str);
    if (str.size() == 1 && str[0] == ' ')
    {
        cout << 0 << '\n';
        return 0;
    }
    if (str[0] == ' ') str[0] = 'a';
    if (str[str.size() - 1] = ' ') str[str.size() - 1] = 'a';
    cout << count(str.begin(), str.end(), ' ') + 1 << '\n';
}