#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, b; cin >> n >> m >> b;
    unordered_map<int, int> dict;
    set<int, greater<int>> s;
    int limit = 0;
    for (int i = 0; i < n * m; i++) {
        int input; cin >> input;
        dict[input]++;
        s.insert(input);
        limit = max(input, limit);
    }
    int minTime = INT_MAX, maxBlock = 0;
    for (int i = limit; i >= 0; i--) {
        int time = 0, block = b;
        for (auto j = s.begin(); j != s.end() && time < minTime; j++) {
            if (i - *j < 0) {
                time += abs(i - *j) * 2 * dict[*j];
                block += abs(i - *j) * dict[*j];
            }
            else {
                int t = (i - *j) * dict[*j];
                if (t > block) {
                    time = -1;
                    break;
                }
                time += t;
                block -= t;
            }
        }
        if (minTime > time && time != -1) {
            minTime = time;
            maxBlock = i;
        }
    }
    cout << minTime << ' ' << maxBlock;
}
