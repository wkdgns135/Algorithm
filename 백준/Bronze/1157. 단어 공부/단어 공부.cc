#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    unordered_map<char, int> map;
    int maxVal = 0;
    char maxChar = '?';
    for (int i = 0; i < str.size(); i++) {
        char c = toupper(str[i]);
        map[c]++;
        if (map[c] == maxVal)maxChar = '?';
        else if (map[c] > maxVal) {
            maxVal = map[c];
            maxChar= c;
        }
    }
    cout << maxChar;
}