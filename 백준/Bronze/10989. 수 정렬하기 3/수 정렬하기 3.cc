#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, input; cin >> n;
    vector<int> v(10001);
    for (int i = 0; i < n; i++) {
        cin >> input;
        v[input]++;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << '\n';
        }
    }
}
