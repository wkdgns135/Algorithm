#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        
        int minVal = n + 1;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].second < minVal) {
                minVal = v[i].second;
                answer++;
            }
        }
        cout << answer << '\n';
    }
}
