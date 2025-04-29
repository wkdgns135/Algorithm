#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, X;
int Q;
vector<int> station[100001];
int dist[505][505];

int getNode(int univ, int busNum)
{
	return univ * X + (busNum - 1);
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> X;

	// 각 정류장마다 지나가는 노선 저장
	for (int i = 1; i <= N; ++i)
	{
		for (int u = 0; u < 5; ++u)
		{
			int bus;
			cin >> bus;
			int node = getNode(u, bus);
			station[i].push_back(node);
		}
	}

	int totalBuses = 5 * X;

	// 인접 행렬 초기화
	for (int i = 0; i < totalBuses; ++i)
		for (int j = 0; j < totalBuses; ++j)
			dist[i][j] = (i == j) ? 0 : INF;

	// 같은 정류장을 지나는 노선은 모두 연결됨 (환승 가능)
	for (int i = 1; i <= N; ++i)
	{
		auto& buses = station[i];
		for (int j = 0; j < 5; ++j)
		{
			for (int k = j + 1; k < 5; ++k)
			{
				int u = buses[j];
				int v = buses[k];
				dist[u][v] = dist[v][u] = 1;
			}
		}
	}

	// Floyd-Warshall
	for (int k = 0; k < totalBuses; ++k)
	{
		for (int i = 0; i < totalBuses; ++i)
		{
			for (int j = 0; j < totalBuses; ++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	cin >> Q;
	while (Q--)
	{
		int u, v;
		cin >> u >> v;
		int ans = INF;
		for (int busFrom : station[u])
		{
			for (int busTo : station[v])
			{
				ans = min(ans, dist[busFrom][busTo]);
			}
		}
		cout << (ans == INF ? -1 : ans + 1) << '\n';
	}

}