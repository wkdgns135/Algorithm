#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    unordered_map<int, int> seen;  // value -> index
    vector<int> seq;

    int cur = N % P;
    while (seen.find(cur) == seen.end()) {
        seen[cur] = seq.size();
        seq.push_back(cur);
        cur = (cur * N) % P;
    }

    // 반복 구간 시작 인덱스
    int loop_start = seen[cur];
    int unique_in_loop = set<int>(seq.begin() + loop_start, seq.end()).size();

    cout << unique_in_loop << "\n";
    return 0;
}
