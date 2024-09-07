#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;

    if (str.size() < 3) {
        cout << stoi(str);
        return 0;
    }
    int answer = 99;
    
    for (int i = 100; i <= stoi(str); i++) {
        string s = to_string(i);
        int diff = s[1] - s[0];
        answer++;
        for (int j = 1; j < s.size()-1; j++) {
            if (diff != s[j + 1] - s[j]) {
                answer--;
                break;
            }
        }
    }

    cout << answer;
}