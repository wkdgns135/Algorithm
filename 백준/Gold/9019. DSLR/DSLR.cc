#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        queue<pair<int, string>> bfs;
        bfs.push({ a, "" });
        vector<bool> visited(10000, false); // visited 배열로 변경
        visited[a] = true;

        while (!bfs.empty()) {
            int s = bfs.front().first;
            string o = bfs.front().second;
            bfs.pop();
            if (s == b) {
                cout << o << '\n';
                break;
            }

            // 'D' 연산
            int temp = s * 2 % 10000;
            if (!visited[temp]) {
                bfs.push({ temp, o + "D" });
                visited[temp] = true;
            }

            // 'S' 연산
            temp = (s == 0) ? 9999 : s - 1;
            if (!visited[temp]) {
                bfs.push({ temp, o + "S" });
                visited[temp] = true;
            }

            // 'L' 연산
            temp = (s % 1000) * 10 + (s / 1000);
            if (!visited[temp]) {
                bfs.push({ temp, o + "L" });
                visited[temp] = true;
            }

            // 'R' 연산
            temp = (s / 10) + (s % 10) * 1000;
            if (!visited[temp]) {
                bfs.push({ temp, o + "R" });
                visited[temp] = true;
            }
        }
    }
}
