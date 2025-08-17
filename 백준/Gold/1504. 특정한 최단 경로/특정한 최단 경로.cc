#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

#define CHECK(x) if (x == INT_MAX) { cout << -1; return 0; }

int n, e;
vector<vector<pair<int, int>>> graph;

int ShortCut(int start, int end)
{
	vector<int> mdt(n + 1, INT_MAX);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	mdt[start] = 0;

	while (!pq.empty())
	{
		auto [cost, node] = pq.top();
		pq.pop();

		if (mdt[node] != -cost) continue;
		if (node == end) break;
		for (auto [nextCost, nextNode] : graph[node])
		{
			if (mdt[nextNode] > nextCost - cost)
			{
				mdt[nextNode] = nextCost - cost;
				pq.push({ -mdt[nextNode], nextNode });
			}
		}
	}

	return mdt[end];
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> e;
	graph.resize(n + 1);

	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	int v1, v2; cin >> v1 >> v2;
	int sv1 = ShortCut(1, v1); CHECK(sv1);
	int sv2 = ShortCut(1, v2); CHECK(sv2);
	int v1v2 = ShortCut(v1, v2); CHECK(v1v2);
	int v1n = ShortCut(v1, n); CHECK(v1n);
	int v2n = ShortCut(v2, n); CHECK(v2n);

	cout << min(sv1 + v1v2 + v2n, sv2 + v1v2 + v1n);
}
