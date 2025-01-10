#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;

    vector<pair<int, int>> gem(n);
    vector<int> bag(k);
    for (int i = 0; i < n; i++)cin >> gem[i].first >> gem[i].second;
    for (int i = 0; i < k; i++)cin >> bag[i];
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());
    
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0, j = 0; i < k; i++) {
        for (j; j < n && gem[j].first <= bag[i]; j++) {
            pq.push(gem[j].second);
        }
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
}
