#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x; cin >> x;
    vector<int> v(1, 64);
    int sum = 64;
    while (sum > x) {
        sum = accumulate(v.begin(), v.end(), 0);
        if (sum > x) {
            int minIndex = min_element(v.begin(), v.end()) - v.begin();
            v[minIndex] /= 2;
            if (accumulate(v.begin(), v.end(), 0) >= x)continue;
            v.push_back(v[minIndex]);
        }
    }
    cout << v.size();
}
