#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int a = v[0], b = 0;
    int count = 1, preCount = 1, maxCount = 1;

    for (int i = 1; i < n; i++) {
        if (a == v[i] || b == v[i]) count++;
        else {
            count = preCount + 1;
            a = v[i - 1];
            b = v[i];
        }
        if (v[i - 1] == v[i])preCount++;
        else preCount = 1;
        maxCount = max(maxCount, count);
    }
    cout << maxCount;
}
