#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m; cin >> n;
    unordered_map<string, bool> dict;
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        dict[str] = true;
    }
    cin >> m;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string str; cin >> str;
        if (dict[str] == true)
        {
            cnt++;
            if (cnt >= (n + 1) / 2)
            {
                cout << i + 1;
                return 0;
            }
            dict[str] = false;
        }
    }
}