#include <bits/stdc++.h>
using namespace std;

int n, m, answer = 0;
vector<int> v;
vector<bool> visited;

void bt(int depth, int sum) {
    if (depth == 3) {
        if (sum > m)return;
        answer = m - sum < m - answer ? sum : answer;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i])continue;
        visited[i] = true;
        bt(depth + 1, sum + v[i]);
        visited[i] = false;
    }
} 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    v.resize(n); for (int i = 0; i < n; i++) cin >> v[i];
    visited.resize(n);
    bt(0, 0);
    cout << answer;
}