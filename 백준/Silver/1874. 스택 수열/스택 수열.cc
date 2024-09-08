#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    stack<int> s;
    string answer = "";
    reverse(v.begin(), v.end());

    for (int i = 1; !v.empty(); i++) {
        if (s.size() > v.size()) {
            cout << "NO"; return 0;
        }
        if (!s.empty() && s.top() == v.back()) {
            answer += '-';
            s.pop(); v.pop_back();
            i--;
        }
        else {
            answer += '+';
            s.push(i);
        }
    }

    for (char& c : answer)cout << c << '\n';
}