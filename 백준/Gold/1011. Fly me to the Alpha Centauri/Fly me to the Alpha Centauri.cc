#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    vector<int> v(46342);
    for (int i = 1; i < 46342; i++) v[i] = i + v[i - 1];

    while (t--) {
        int x, y; cin >> x >> y;
        int diff = y - x;
        int result = sqrt(diff);
        result += lower_bound(v.begin(), v.end(), diff - v[result]) - v.begin();
        cout << result << '\n';
    }
}