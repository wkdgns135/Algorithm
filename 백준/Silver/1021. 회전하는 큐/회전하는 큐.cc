#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    deque<int> dq; for (int i = 1; i <= n; i++)dq.push_back(i);
    queue<int> q; 
    for (int i = 0; i < m; i++) { 
        int num; cin >> num;
        q.push(num);
    }
    int answer = 0;
    while (!q.empty()) {
        int num = q.front();
        
        int fd = distance(dq.begin(),find(dq.begin(), dq.end(), num));
        int bd = distance(find(dq.begin(), dq.end(), num), dq.end());

        if (fd == 0) {
            dq.pop_front();
            q.pop();
        }
        else if (fd < bd) {
            dq.push_back(dq.front());
            dq.pop_front();
            answer++;
        }
        else {
            dq.push_front(dq.back());
            dq.pop_back();
            answer++;
        }
    }
    cout << answer;
}