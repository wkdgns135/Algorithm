#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    
    vector<int> v(101, INT_MAX);
    unordered_map<int, int> map;
    for (int i = 0; i < n + m; i++) {
        int a, b; cin >> a >> b;
        map[a] = b;
    }

    stack<int> bfs;
    bfs.push(1);
    v[1] = 0;

    while (!bfs.empty()) {
        int index = bfs.top();
        int count = v[index];
        bfs.pop();

        if (map[index] != 0) {
            if (v[map[index]] > count) {
                v[map[index]] = count;
                bfs.push(map[index]);
            }
            continue;
        }

        for (int i = 1; i <= 6; i++) {
            int next = index + i;
            if (next < 101 && v[next] > count + 1) {
                v[next] = count + 1;
                bfs.push(next);
            }
        }
    }
    cout << v[100];
}