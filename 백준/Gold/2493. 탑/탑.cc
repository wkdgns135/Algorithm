#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        while (!s.empty() && s.top().second < num) s.pop();
        if (s.empty()) {
            cout << 0 << ' ';
            s.push({ i, num });
            continue;
        }
        cout << s.top().first + 1 << ' ';
        s.push({ i, num });
    }
}
