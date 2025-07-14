#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer,path;
vector<int> visited;

void dfs(vector<vector<string>>& tickets, int depth) {
    if (depth == tickets.size()) {
        answer = path;
        return;
    }

    for (int i = 0; i < tickets.size(); ++i) {
        if (!visited[i] && tickets[i][0] == path.back()) {
            visited[i] = 1;
            path.push_back(tickets[i][1]);
            dfs(tickets, depth + 1);
            if (!answer.empty()) {
                return;
            }
            path.pop_back();
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    visited.resize(tickets.size(), 0);
    path = {"ICN"};

    sort(tickets.begin(), tickets.end());
    dfs(tickets, 0);

    return answer;
}