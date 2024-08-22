#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    while (n--)cin >> v[n];
    int count = 0; n = 0;
    while (n != k) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] + n <= k) {
                n += v[i];
                count++;
                break;
            }
        }
    }
    cout << count;
}