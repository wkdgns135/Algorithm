#include <bits/stdc++.h>

using namespace std;

int N;

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)return a.second > b.second;
        return a.first > b.first;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;
    int x, y;
    while (N--) {
        cin >> x >> y;
        pq.push({ x, y });
    }

    while (!pq.empty()) {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        cout << x << ' ' << y << '\n';
    }
    return 0;
}