#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int answer = n;
    while (n--) {
        string str; cin >> str;
        unordered_map<char, bool> map;
        map[str[0]] = true;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] != str[i - 1]) {
                if (map[str[i]]) {
                    answer--;
                    break;
                }
                map[str[i]] = true;
            }
        }
    }
    cout << answer;
}