#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int e, s, m; cin >> e >> s >> m;
    int E, S, M; E = S = M = 1;
    int i = 1;
    for (i; e != E || s != S || m != M; i++) {
        E = clamp((E + 1) % 16, 1, 15);
        S = clamp((S + 1) % 29, 1, 28);
        M = clamp((M + 1) % 20, 1, 19);
    }
    cout << i;
}
