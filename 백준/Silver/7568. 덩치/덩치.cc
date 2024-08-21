#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second)count++;
        }
        cout << count << ' ';
    }
}