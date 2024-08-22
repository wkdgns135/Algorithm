#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    int max = -INT_MAX, min = INT_MAX;
    while (n--) {
        int input; cin >> input;
        max = std::max(max, input);
        min = std::min(min, input);
    }
    cout << min << ' ' << max;
}