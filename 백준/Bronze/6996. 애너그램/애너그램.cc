#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b; cin >> a >> b;
        unordered_map<char, int> dict;
        for (const char& c : a)dict[c]++;
        for (const char& c : b)dict[c]--;
        if (any_of(dict.begin(), dict.end(), [](auto &x) {return x.second != 0;}))
            cout << a << " & " << b << " are NOT anagrams.\n";
        else
            cout << a << " & " << b << " are anagrams.\n";
    }
}
