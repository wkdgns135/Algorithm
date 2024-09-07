#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    unordered_map<string, bool> dict = { {"c=", true}, {"c-", true}, {"dz=", true}, {"d-", true}, {"lj", true}, {"nj", true}, {"s=", true}, {"z=", true} };
    int answer = 0;

    for (int i = 0; i < str.size(); i++) {
        if (dict[str.substr(i, 2)]) {
            i++;
            answer++;
            continue;
        }
        if (dict[str.substr(i, 3)]) {
            i += 2;
            answer++;
            continue;
        }
        answer++;
    }
    cout << answer;
}