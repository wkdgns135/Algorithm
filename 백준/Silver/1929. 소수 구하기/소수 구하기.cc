#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> M >> N;
    vector<int> v(N+1);
    for (int i = 2; i <= N; i++)v[i] = i;
    for (int i = 2; i <= N; i++) {
        if (!v[i])continue;
        for (int j = i * 2; j <= N; j += i)v[j] = 0;
    }
    for (int i = M; i <= N; i++)if (v[i] != 0)cout << v[i] << '\n';
}