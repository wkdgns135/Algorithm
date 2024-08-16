#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned short int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    int input;
    for (int i = 0; i < N * N; i++) {
        cin >> input;
        pq.push(input);
        if (pq.size() > N) pq.pop(); // Keep only the largest N elements
    }
    cout << pq.top(); // The N-th largest element
    return 0;
}
