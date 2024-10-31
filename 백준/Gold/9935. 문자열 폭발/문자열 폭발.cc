#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    string answer = "";
    for (int i = 0; i < s1.size(); i++) {
        answer.push_back(s1[i]);
        if (answer.size() < s2.size()) continue;
        int index = answer.size() - s2.size();
        if (answer.substr(index, s2.size()) == s2) answer.erase(index);
    }
    if (answer.empty())cout << "FRULA";
    else cout << answer;
}
