#include <bits/stdc++.h>

using namespace std;

int T, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> M;
        double answer = 0;
        for (double i = 1; i <= M; i++) {
            answer += log10(i);
        }
        cout << (int)answer + 1 << '\n';
    }
    return 0;
}