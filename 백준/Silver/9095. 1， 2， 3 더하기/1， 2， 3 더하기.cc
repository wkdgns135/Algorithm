#include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    vector<int> v(11);
    v[0] = 1; v[1] = 2; v[2] = 4;
    for (int i = 3; i < 11; i++)v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << v[N-1] << "\n";
    }
    
    return 0;
}