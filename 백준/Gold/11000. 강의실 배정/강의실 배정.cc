#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    int answer = 1;
    for (int i = 1; i < n; i++) {
        if (pq.top() > v[i].first) {
            pq.push(v[i].second);
            answer++;
        }
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << answer;
}
