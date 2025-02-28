#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<vector<bool>> v(n, vector<bool>(m, true));
	
	for (int i = 0; i < k; i++)
	{
		int r, c; cin >> r >> c;
		v[r - 1][c - 1] = false;
	}
	
	int maxVal = 0;
	int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == true)continue;
			int cnt = 1;
			queue<pair<int, int>> bfs;
			bfs.push({ i,j });
			v[i][j] = true;
			while (!bfs.empty())
			{
				int x, y; tie(y, x) = bfs.front();
				bfs.pop();
				for (int k = 0; k < 4; k++)
				{
					int xx = x + offset[k][0];
					int yy = y + offset[k][1];
					if (xx < 0 || xx >= m || yy < 0 || yy >= n || v[yy][xx])continue;
					bfs.push({ yy, xx });
					v[yy][xx] = true;
					cnt++;
				}
			}
			maxVal = max(maxVal, cnt);
		}
	}
	cout << maxVal;
}
