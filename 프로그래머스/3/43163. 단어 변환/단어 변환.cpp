#include <bits/stdc++.h>

using namespace std;

bool isOneLetterDifferent(string a, string b) {
    int diff_count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff_count++;
        if (diff_count > 1) return false;
    }
    return diff_count == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), false);
    queue<pair<int, string>> bfs;
    bfs.push({0, begin});

    while (!bfs.empty()) {
        string str = bfs.front().second;
        int steps = bfs.front().first;
        bfs.pop();

        if (str == target) return steps;

        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && isOneLetterDifferent(str, words[i])) {
                visited[i] = true;
                bfs.push({steps + 1, words[i]});
            }
        }
    }

    return answer;
}