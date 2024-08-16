#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned short int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    int input;
    for (int i = 0; i < N * N; i++) {
        cin >> input;
        pq.push(input);
        if (pq.size() > N) pq.pop();
    }
    cout << pq.top();
    return 0;
}
