#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v, vv;
vector<bool> used;
void BackTracking(int depth, int index) {
    if (depth == m) {
        for (int &i : vv)cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = index; i < n; i++) {
        if (used[i])continue;
        vv[depth] = v[i];
        used[i] = true;
        BackTracking(depth + 1 , i + 1);
        used[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v = vector<int>(n), vv = vector<int>(m), used = vector<bool>(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    BackTracking(0, 0);
}
