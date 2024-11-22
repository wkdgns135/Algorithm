#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string encrypted;
    cin >> encrypted;

    int N = encrypted.size();
    int R = 0, C = 0;

    // R과 C 찾기
    for (int r = 1; r * r <= N; r++) {
        if (N % r == 0) {
            int c = N / r;
            if (r <= c) {
                R = r;
                C = c;
            }
        }
    }

    // 행렬 재구성 및 복호화
    vector<vector<char>> matrix(R, vector<char>(C));
    int index = 0;
    for (int c = 0; c < C; c++) {
        for (int r = 0; r < R; r++) {
            matrix[r][c] = encrypted[index++];
        }
    }

    string decrypted;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            decrypted += matrix[r][c];
        }
    }

    cout << decrypted << '\n';
}
