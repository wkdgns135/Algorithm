#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    unordered_map<string, bool> dict;
    while (n--) {
        string s; cin >> s;
        dict[s] = true;
    }
    int answer = 0;
    while (m--) {
        string s; cin >> s;
        if (dict[s])answer++;
    }
    cout << answer;
}