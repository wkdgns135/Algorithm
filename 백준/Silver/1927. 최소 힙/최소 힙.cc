#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int input; cin >> input;
        if (!input) {
            if (pq.empty())cout << 0 << '\n';
            else { cout << pq.top() << '\n'; pq.pop(); }
        }
        else pq.push(input);
    }
}