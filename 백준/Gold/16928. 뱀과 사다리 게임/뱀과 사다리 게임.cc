#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;

	vector<int> graph(100, -1), visited(100, INT_MAX);

	for (int i = 0; i < n + m; i++)
	{
		int a, b; cin >> a >> b;
		a--, b--;
		graph[a] = b;
	}

	queue<int> bfs;
	bfs.push(0);
	visited[0] = 0;

	while (!bfs.empty())
	{
		int node = bfs.front();
		bfs.pop();

		if (node == 99)
		{
			cout << visited[node];
			break;
		}
		for (int i = node + 1; i <= node + 6 && i < 100; i++)
		{
			int next = graph[i] == -1 ? i : graph[i];
			if (visited[next] > visited[node] + 1)
			{
				visited[next] = visited[node] + 1;
				bfs.push(next);
			}
		}
	}
}