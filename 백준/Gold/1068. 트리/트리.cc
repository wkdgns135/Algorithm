#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> depth(n);
	vector<vector<int>> graph(n);

	for (int i = 0; i < n; i++) {
		int parent; cin >> parent;
		if (parent == -1)continue;
		depth[parent]++;
		graph[parent].push_back(i);
	}

	int target; cin >> target;
	for (int i = 0; i < n; i++) {
		for (const int& node : graph[i]) {
			if (node == target) {
				depth[i]--;
				break;
			}
		}
	}
	
	queue<int> bfs;
	bfs.push(target);
	while (!bfs.empty()) {
		int node = bfs.front();
		bfs.pop();
		depth[node] = -1;
		for (const int& next : graph[node]) {
			bfs.push(next);
		}
	}

	cout << count(depth.begin(), depth.end(), 0);
}
