#include <bits/stdc++.h>
using namespace std;

int N, C;

void BackTracking(int row, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == N) {
        C++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (cols[col] || diag1[row + col] || diag2[row - col + N - 1])continue;
        cols[col] = diag1[row + col] = diag2[row - col + N - 1] = true;
        BackTracking(row + 1, cols, diag1, diag2);
        cols[col] = diag1[row + col] = diag2[row - col + N - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<bool> cols(N, false); 
    vector<bool> diag1(2 * N - 1, false);
    vector<bool> diag2(2 * N - 1, false); 

    BackTracking(0, cols, diag1, diag2);

    cout << C;
}
