#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, input; cin >> n;
    unordered_map<int, int> dict;
    for (int i = 0; i < n; i++) {
        cin >> input;
        dict[input]++;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < dict[i]; j++) {
            cout << i << '\n';
        }
    }
}
