#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid, dp;
int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

// 메모이제이션을 활용한 DFS 함수
int dfs(int y, int x)
{
	if (dp[y][x] != -1) return dp[y][x]; // 이미 계산된 경우 반환

	dp[y][x] = 1; // 기본 길이는 1
	for (int i = 0; i < 4; i++)
	{
		int yy = y + offset[i][0];
		int xx = x + offset[i][1];

		if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
		if (grid[yy][xx] > grid[y][x])
		{
			dp[y][x] = max(dp[y][x], 1 + dfs(yy, xx));
		}
	}
	return dp[y][x];
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n;
	grid.assign(n, vector<int>(n));
	dp.assign(n, vector<int>(n, -1)); // dp 배열 초기화

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer = max(answer, dfs(i, j)); // 각 위치에서 DFS 수행
		}
	}

	cout << answer;
}
