#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        int t, p; cin >> t >> p;
        if (i + t > n)continue;
        t--;
        v[i + t] = max(*max_element(v.begin(), v.begin() + i) + p, v[i + t]);
    }

    cout << *max_element(v.begin(), v.end());
}
