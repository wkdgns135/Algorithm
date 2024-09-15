#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<bool> v(n + 1, true);
    for (int i = 2; i <= n && k; i++) {
        if (!v[i])continue;
        for (int j = i; j <= n; j += i) {
            if (!v[j])continue;
            v[j] = false;
            k--;
            if (!k)cout << j;
        }
    }
}