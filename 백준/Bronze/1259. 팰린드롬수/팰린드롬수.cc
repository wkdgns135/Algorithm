#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    while (s != "0") {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) break;
            else left++, right--;
        }
        if (s[left] != s[right])cout << "no" << '\n';
        else cout << "yes" << '\n';
        cin >> s;
    }
}
