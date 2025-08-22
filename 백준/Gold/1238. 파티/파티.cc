#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

void short_cut(vector<int>& mdt, vector<vector<pair<int, int>>>& graph, int start, int end)
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	mdt[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		auto [cost, node] = pq.top();
		pq.pop();

		if (mdt[node] != cost) continue;
		if (node == end) break;
		for (auto [nextNode, nextCost] : graph[node])
		{
			if (mdt[nextNode] > nextCost + cost)
			{
				mdt[nextNode] = nextCost + cost;
				pq.push({ mdt[nextNode], nextNode });
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m, x; cin >> n >> m >> x;

	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1, c });
	}
	x--;
	vector<int> x2other(n, INT_MAX);
	short_cut(x2other, graph, x, -1);
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == x)continue;
		vector<int> result(n, INT_MAX);
		short_cut(result, graph, i, x);
		answer = max(answer, result[x] + x2other[i]);
	}
	cout << answer;
}