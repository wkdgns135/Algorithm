#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int m, n; cin >> m >> n;
    unordered_map<string, int> nameMap;
    unordered_map<int, string> numMap;
    for (int i = 1; i <= m; i++) {
        string str; cin >> str;
        nameMap[str] = i;
        numMap[i] = str;
    }
    while (n--) {
        string str; cin >> str;
        if (str[0] >= '0' && str[0] <= '9')cout << numMap[stoi(str)] << '\n';
        else cout << nameMap[str] << '\n';
    }

}