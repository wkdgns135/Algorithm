#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    string S;
    cin >> N >> M >> K >> S;

    vector<bool> infected(N, false);

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            for (int j = max(0, i - K); j <= min(N - 1, i + K); ++j) {
                infected[j] = true;
            }
        }
    }

    int cnt = count(infected.begin(), infected.end(), true);
    cout << (cnt <= M ? "Yes" : "No");
}
