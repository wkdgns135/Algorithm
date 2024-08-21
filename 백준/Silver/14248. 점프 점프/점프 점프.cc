#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, s, count = 0;
    cin >> n;
    vector<int> a(n);
    vector<bool> visit(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    cin >> s;
    stack<int> dfs;
    dfs.push(s - 1);
    visit[s - 1] = true;
    
    while (!dfs.empty()) {
        int i = dfs.top();
        dfs.pop();
        count++;
        int left = i - a[i], right = i + a[i];
        if (left >= 0 && !visit[left]) {
            visit[left] = true;
            dfs.push(i - a[i]);
        }
        if (right < n && !visit[right]) {
            visit[right] = true;

            dfs.push(right);
        }
    }
    cout << count;
}

