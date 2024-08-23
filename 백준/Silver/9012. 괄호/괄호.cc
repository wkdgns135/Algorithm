#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    getline(cin, str, '\n');
    int n = stoi(str); 

    while (n--) {
        getline(cin, str, '\n');
        unordered_map<char, int> map;
        bool flag = true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[') { map[str[i]]++; }
            if (str[i] == ')') {
                if (--map['('] < 0) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && !map['(']) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

}