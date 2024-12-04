#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n); 
    for (int i = 0; i < n; i++)cin >> v[i];

    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] < v[i + 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "DECREASING";
        return 0;
    }

    flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "INCREASING";
    }
    else {
        cout << "NEITHER";
    }
}
