#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int f, s, g, u, d; cin >> f >> s >> g >> u >> d;

	queue<int> bfs;
	vector<int> visited(f + 1, -1);
	bfs.push(s);
	visited[s] = 0;

	while (!bfs.empty()) {
		int node = bfs.front();
		bfs.pop();
		if (node == g)break;

		if (node - d > 0 && visited[node - d] == -1) {
			visited[node - d] = visited[node] + 1;
			bfs.push(node - d);
		}
		if (node + u <= f && visited[node + u] == -1) {
			visited[node + u] = visited[node] + 1;
			bfs.push(node + u);
		}
	}
	if (visited[g] == -1)cout << "use the stairs";
	else cout << visited[g];
}
