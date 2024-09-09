#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
void BackTracking(int depth) {
    if (depth == m) {
        for (int& i : v)cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        v[depth] = i;
        BackTracking(depth + 1);
        v[depth] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v = vector<int>(m);
    BackTracking(0);
}
