#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        queue<pair<int,int>> q;
        priority_queue<int,vector<int>> pq;

        for (int i = 0; i < n; i++) { 
            int input; cin >> input;
            q.push({ input, i });
            pq.push(input);
        }
        int count = 1;
        while (true) {
            while (pq.top() != q.front().first) {
                auto p = q.front();
                q.pop();
                q.push(p);
            }
            if (q.front().second == m)break;
            pq.pop();
            q.pop();
            count++;
        }
        cout << count << '\n';
    }
}
