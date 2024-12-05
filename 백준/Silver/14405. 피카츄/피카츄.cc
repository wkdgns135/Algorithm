#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    unordered_map<string, bool> dict = { {"pi", true}, {"ka", true}, {"chu", true} };
    for (int i = 0; i < s.size(); i++) {
        if (dict[s.substr(i, 2)]) {
            i++;
            continue;
        }
        else if (dict[s.substr(i, 3)]) {
            i += 2;
            continue;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
