#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    constexpr int size = 246912;
    vector<bool> v(size + 1, true);
    for (int i = 2; i < sqrt(size); i++) {
        if (!v[i])continue;
        for (int j = i + i; j <= size; j+=i) {
            v[j] = false;
        }
    }

    while (true) {
        cin >> n;
        if (!n) break;
        cout << accumulate(v.begin() + n + 1, v.begin() + n * 2 + 1, 0) << '\n';
    }
}
