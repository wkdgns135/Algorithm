#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int count = 1;
    for (int i = 1; i < n; i += 6 * count, count++);
    cout << count;
}