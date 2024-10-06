#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int Find(int x) {
    if (x == v[x])return x;
    return v[x] = Find(v[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b)return;

    if (a < b)v[b] = a;
    else v[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    v = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)v[i] = i;
    while (m--) {
        int oper, a, b; cin >> oper >> a >> b;
        if (oper) {
            if (Find(a) == Find(b))cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else {
            Union(a, b);
        }
    }
}
