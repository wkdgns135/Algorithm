#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    vector<string> v(N);
    while (N--) cin >> v[N];
    sort(v.begin(), v.end(), [](string a, string b) {
        if (a.size() != b.size())return a.size() < b.size();
        return a < b;
        });
    v.erase(unique(v.begin(), v.end()), v.end());
    for (string str : v)cout << str << '\n';
}