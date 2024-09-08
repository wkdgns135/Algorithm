#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)v[i] = i;
    
    int index = 0;
    cout << '<';
    while (!v.empty()) {
        index = (index + k - 1) % v.size();
        if (v.size() == 1) cout << v[index] + 1 << ">";
        else cout << v[index] + 1 << ", ";
        v.erase(v.begin() + index);
    }
}