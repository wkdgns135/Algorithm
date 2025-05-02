#include <bits/stdc++.h>
using namespace std;

vector<tuple<bool, int, int>> targets;
vector<pair<int, int>> virus;
vector<vector<int>> grid;
vector<pair<int, int>> target;

int n, m, answer = 0;
int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int BFS()
{
	for (auto& [isUsed, y, x] : targets) grid[y][x] = isUsed;
	queue<pair<int, int>> bfs;
	for (auto& [y, x] : virus)bfs.push({ y, x });
	while (!bfs.empty())
	{
		auto& [y, x] = bfs.front();
		bfs.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + offset[i][0];
			int yy = y + offset[i][1];

			if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[yy][xx])continue;
			bfs.push({ yy, xx });
			grid[yy][xx] = 2;
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result += grid[i][j] == 0;
		}
	}

	return result;
}

void BackTracking(int depth, int index = 0)
{
	if (depth == 3)
	{
		answer = max(answer, BFS());
		return;
	}

	for (int i = index; i < targets.size(); i++)
	{
		bool& isUsed = get<0>(targets[i]);
		if (isUsed)continue;
		isUsed = true;
		BackTracking(depth + 1, i);
		isUsed = false;
	}
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	grid.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 0)targets.push_back({ false, i,j });
			else if (grid[i][j] == 2)virus.push_back({ i ,j });
		}
	}
	BackTracking(0);
	cout << answer;
}
