#include <bits/stdc++.h>
using namespace std;

int n, m;
int offset[8][2] = { {0 ,-1}, {-1, -1},{-1, 0},{-1, 1},{0,1},{1,1},{1,0},{1,-1} };

void MoveCloud(vector<pair<int, int>>& clouds, int d, int s)
{
	const int offsetX = offset[d - 1][1] * s;
	const int offsetY = offset[d - 1][0] * s;

	for (auto& [y, x] : clouds)
	{
		x = (x + offsetX % n + n) % n;
		y = (y + offsetY % n + n) % n;
	}
}

void IncreaseWater(vector<vector<int>>& grid, vector<pair<int, int>>& clouds)
{
	for (auto& [y, x] : clouds)
	{
		grid[y][x]++;
	}
}

void DuplicateWater(vector<vector<int>>& grid, vector<pair<int, int>>& clouds)
{
	vector<int> sumArr;
	for (auto& [y, x] : clouds)
	{
		int sum = 0;
		for (int i = 1; i < 8; i += 2)
		{
			int xx = x + offset[i][1];
			int yy = y + offset[i][0];
			if (xx < 0 || xx >= n || yy < 0 || yy >= n || !grid[yy][xx])continue;
			sum++;
		}
		sumArr.push_back(sum);
	}
	for (int i = 0; i < clouds.size(); i++)
	{
		auto& [y, x] = clouds[i];
		grid[y][x] += sumArr[i];
	}
}

void CreateClouds(vector<vector<int>>& grid, vector<pair<int, int>>& clouds)
{
	vector<pair<int, int>> newClouds;
	vector<vector<bool>> isUsed(n, vector<bool>(n));
	for (auto& [y, x] : clouds) isUsed[y][x] = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] >= 2 && !isUsed[i][j])
			{
				grid[i][j] -= 2;
				newClouds.push_back({ i, j });
			}
		}
	}
	swap(clouds, newClouds);
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	vector<pair<int, int>> clouds = { {n - 1, 0}, {n - 2, 0}, {n - 1, 1}, {n - 2, 1} };

	while (m--)
	{
		int d, s; cin >> d >> s;
		MoveCloud(clouds, d, s);
		IncreaseWater(grid, clouds);
		DuplicateWater(grid, clouds);
		CreateClouds(grid, clouds);
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer += grid[i][j];
		}
	}
	cout << answer;
}
