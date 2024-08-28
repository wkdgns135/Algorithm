#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b; cin >> a >> b;
    int min = INT_MAX;
    queue<pair<long, int>> bfs;
    bfs.push({ a , 0});

    while (!bfs.empty()) {
        long long n = bfs.front().first;
        int depth = bfs.front().second;

        bfs.pop();
        if (n == b)min = std::min(min, depth);
        if (n > b)continue;
        bfs.push({ n * 2 ,depth + 1});
        bfs.push({ stoll(to_string(n) + "1"), depth + 1});
    }
    cout << ((min == INT_MAX) ? -1 : min + 1);
}
