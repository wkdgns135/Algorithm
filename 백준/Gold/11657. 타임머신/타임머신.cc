#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		graph[a].push_back({ c, b });
	}

	vector<long> mdt(n, INT_MAX);
	mdt[0] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int node = 0; node < n; node++)
		{
			if (mdt[node] == INT_MAX) continue;
			for (auto [nextCost, nextNode] : graph[node])
			{
				if (mdt[nextNode] > mdt[node] + nextCost)
				{
					mdt[nextNode] = mdt[node] + nextCost;
				}
			}
		}
	}

	for (int node = 0; node < n; node++)
	{
		for (auto [nextCost, nextNode] : graph[node])
		{
			if (mdt[node] == INT_MAX) continue;
			if (mdt[nextNode] > mdt[node] + nextCost)
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	for (int node = 1; node < n; node++)
	{
		cout << (mdt[node] == INT_MAX ? -1 : mdt[node]) << '\n';
	}
}