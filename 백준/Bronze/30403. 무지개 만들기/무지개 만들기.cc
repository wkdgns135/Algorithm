#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char, bool> dict;
    for (char& c : s)dict[c] = true;
    string small = "roygbiv", large = "ROYGBIV";
    bool resultSmall = any_of(small.begin(), small.end(), [&dict](char &c){return !dict[c]; });
    bool resultLarge = any_of(large.begin(), large.end(), [&dict](char &c){return !dict[c]; });
    if (!resultSmall && !resultLarge)cout << "YeS";
    else if (!resultSmall)cout << "yes";
    else if (!resultLarge)cout << "YES";
    else cout << "NO!";
}
