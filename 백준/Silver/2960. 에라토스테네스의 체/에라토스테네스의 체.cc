#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<bool> v(n + 1, true);
    for (int i = 2; i <= n && k; i++) {
        if (!v[i])continue;
        for (int j = i; j <= n; j += i) {
            if (!v[j])continue;
            v[j] = false;
            if (!--k)cout << j;
        }
    }
}