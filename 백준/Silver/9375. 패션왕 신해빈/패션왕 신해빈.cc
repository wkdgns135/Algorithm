#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int answer = 1;
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;
            map[b]++;
        }
        for (auto& i : map) answer *= i.second + 1;
        cout << answer - 1 << '\n';
    }
}
