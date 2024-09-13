#include<bits/stdc++.h>
using namespace std;

bool QueueIsEmpty(queue<int>& q) {
    if (!q.empty()) return false;
    cout << -1 << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    queue<int> q;

    while (n--) {
        string s; cin >> s;
        if (s == "push") {
            int num; cin >> num;
            q.push(num);
        }
        else if (s == "pop") {
            if (!QueueIsEmpty(q)) {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (s == "size") cout << q.size() << '\n';
        else if (s == "empty") cout << q.empty() << '\n';
        else if (s == "front") { if (!QueueIsEmpty(q))cout << q.front() << '\n'; }
        else if (s == "back") { if (!QueueIsEmpty(q))cout << q.back() << '\n'; }
    }
}
