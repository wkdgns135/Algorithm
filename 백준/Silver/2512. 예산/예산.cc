#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int m; cin >> m;

    int left = 0, right = 100000, mid, maxVal = *max_element(v.begin(), v.end());
    int answer = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (maxVal < mid) {
            right = mid - 1;
            continue;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(v[i], mid);
        }
        if (sum <= m) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << answer;
}
