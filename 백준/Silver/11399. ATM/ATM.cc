#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    while (n--)cin >> v[n];
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += accumulate(v.begin(), v.end() - i, 0);
    }
    cout << sum;
}