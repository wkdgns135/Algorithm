#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int x; cin >> x;
	vector<int> visited(x + 1);
	queue<int> bfs;
	bfs.push(x);
	visited[x] = x;

	while (!bfs.empty()) {
		int node = bfs.front();
		bfs.pop();
		if (node == 1)break;
		if (node % 2 == 0 && !visited[node / 2]) {
			visited[node / 2] = node;
			bfs.push(node / 2);
		}
		if (node % 3 == 0 && !visited[node / 3]) {
			visited[node / 3] = node;
			bfs.push(node / 3);
		}
		if (!visited[node - 1]) {
			visited[node - 1] = node;
			bfs.push(node - 1);
		}
	}

	bfs = queue<int>();
	bfs.push(1);
	vector<int> result;
	while (!bfs.empty()) {
		int node = bfs.front();
		bfs.pop();
		result.push_back(node);
		if (node == x)break;
		bfs.push(visited[node]);
	}

	cout << result.size() - 1<< '\n';
	for (auto i = result.rbegin(); i != result.rend(); i++) {
		cout << *i << ' ';
	}
}
