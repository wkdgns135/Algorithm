#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[b].push_back(a);
	}
	vector<int> result(n + 1);
	int maxCnt = 0;
	for (int i = 1; i <= n; i++) {
		
		vector<bool> visited(n + 1);
		queue<int> bfs;
		bfs.push(i);
		visited[i] = true;
		int count = 0;
		while (!bfs.empty()) {
			int node = bfs.front();
			bfs.pop();
			count++;
			for (const int& next : graph[node]) {
				if (visited[next])continue;
				visited[next] = true;
				bfs.push(next);
			}
		}
		result[i] = count;
		maxCnt = max(maxCnt, count);
	}

	for (int i = 1; i <= n; i++) {
		if (maxCnt == result[i])cout << i << ' ';
	}
}
