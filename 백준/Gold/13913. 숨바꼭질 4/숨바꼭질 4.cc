#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100001
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<pair<int, bool>> mdt(MAX_SIZE, { INT_MAX, false });
    vector<int> pre(MAX_SIZE);

    mdt[n].first = 0;
    pq.push({ 0, n });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        if (mdt[index].second)continue;
        if (index == k)break;
        mdt[index].second = true;

        if (index - 1 >= 0 && mdt[index - 1].first > cost + 1) {
            mdt[index - 1].first = cost + 1;
            pq.push({ cost + 1 , index - 1 });
            pre[index - 1] = index;
        }
        if (index + 1 < MAX_SIZE && mdt[index + 1].first > cost + 1) {
            mdt[index + 1].first = cost + 1;
            pq.push({ cost + 1 , index + 1 });
            pre[index + 1] = index;

        }
        if (index * 2 < MAX_SIZE && mdt[index * 2].first > cost + 1) {
            mdt[index * 2].first = cost + 1;
            pq.push({ cost + 1, index * 2 });
            pre[index * 2] = index;
        }
    }

    cout << mdt[k].first << '\n';

    stack<int> s;
    int index = k;
    while (index != n) {s.push(index); index = pre[index];} s.push(index);
    while (!s.empty()) { cout << s.top() << ' '; s.pop(); }
}