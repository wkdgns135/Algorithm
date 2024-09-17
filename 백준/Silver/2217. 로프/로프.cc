#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, answer = 0; cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    while (n--) {
        int num; cin >> num;
        pq.push(num);
    }

    while (!pq.empty()) {
        int num = pq.top();
        answer = max(answer, (int)(num * pq.size()));
        pq.pop();
    }
    cout << answer;
}