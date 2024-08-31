#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v;
    vector<int> idx(N), pre(N, -1);
    vector<int> seq;
    vector<int> save;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        save.push_back(x);
        auto it = lower_bound(v.begin(), v.end(), x);
        int pos = it - v.begin();

        if (it == v.end()) {
            v.push_back(x);
        } else {
            *it = x;
        }

        idx[pos] = i;
        if (pos > 0) {
            pre[i] = idx[pos - 1];
        }
    }

    cout << v.size() << '\n';

    int t = idx[v.size() - 1];
    while (t != -1) {
        seq.push_back(t);
        t = pre[t];
    }

    reverse(seq.begin(), seq.end());
    for (int i : seq) {
        cout << save[i] << ' ';
    }
}
