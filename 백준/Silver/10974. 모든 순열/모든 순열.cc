#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> visited;
vector<int> v;
void BackTracking(int depth) {
    if (depth == n) {
        for (int& i : v) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i - 1])continue;
        visited[i - 1] = true;
        v[depth] = i;
        BackTracking(depth + 1);
        visited[i - 1] = false;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    visited.resize(n);
    v.resize(n);
    BackTracking(0);
}
