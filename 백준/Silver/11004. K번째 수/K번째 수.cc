#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int num; cin >> num;
        pq.push(num);
    }
    while (--k)pq.pop();
    cout << pq.top();
}
