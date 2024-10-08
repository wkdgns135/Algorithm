#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, k, answer = 0;
vector<bool> visited;

void bt(int depth, int weight) {
    if (weight < 500)return;
    if (depth == n) { answer++; return; }

    for (int i = 0; i < n; i++) {
        if (visited[i])continue;
        visited[i] = true;
        bt(depth + 1, weight - k + v[i]);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    v = vector<int>(n); for (int i = 0; i < n; i++)cin >> v[i];
    visited = vector<bool>(n);
    bt(0, 500);
    cout << answer;
}
