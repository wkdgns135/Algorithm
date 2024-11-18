#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    double a, b, v; cin >> a >> b >> v;
    cout << (int)ceil((v - a) / (a - b)) + 1;
}