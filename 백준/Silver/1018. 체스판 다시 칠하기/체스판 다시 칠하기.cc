#include <bits/stdc++.h>
using namespace std;

vector<string> bw = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
vector<string> wb = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int CheckBoard(vector<string>& v, int x, int y) {
    int sumWb = 0, sumBw = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (v[i][j] != bw[i - y][j - x])sumBw++;
            if (v[i][j] != wb[i - y][j - x])sumWb++;
        }
    }
    return min(sumBw, sumWb);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    int answer = INT_MAX;
    vector<string> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            answer = min(answer, CheckBoard(v, j, i));
        }
    }
    cout << answer;
}