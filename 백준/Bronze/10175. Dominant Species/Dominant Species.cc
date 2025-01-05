#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    unordered_map<char, string> charMap = { {'B',"Bobcat"},{'C',"Coyote"},{'M',"Mountain Lion"},{'W',"Wolf"} };
    unordered_map<char, int> valueMap = { {'B',2},{'C',1},{'M',4},{'W',3} };
    while (t--) {
        string location; cin >> location;
        string str; cin >> str;
        unordered_map<char, int> dict;
        for (char& c : str)dict[c] += valueMap[c];

        auto pos = max_element(dict.begin(), dict.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
            });
        char dominant = (*pos).first;
        for (++pos; pos != dict.end(); pos++) {
            if ((*pos).second == dict[dominant]) {
                dominant = ' ';
                break;
            }
        }
        cout << location << ": ";
        if (dominant == ' ')cout << "There is no dominant species\n";
        else cout << "The " << charMap[dominant] << " is the dominant species\n";

    }
}
