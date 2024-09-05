#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n; cin >> m >> n;
	vector<string> v(n);
	priority_queue <pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	vector<vector<int>> mdt(n, vector<int>(m, INT_MAX));
	int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	for (int i = 0; i < n; i++)cin >> v[i];
	
	pq.push({ 0, {0, 0} });
	mdt[0][0] = 0;

	while (!pq.empty()) {
		pair<int, int> pos = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost != mdt[pos.first][pos.second])continue;
		for (int i = 0; i < 4; i++) {
			int xx = pos.second + offset[i][0];
			int yy = pos.first + offset[i][1];

			if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
				if (mdt[yy][xx] > cost + (v[yy][xx] - '0')) {
					mdt[yy][xx] = cost + (v[yy][xx] - '0');
					pq.push({ mdt[yy][xx], {yy, xx} });
				}
			}
		}
	}
	cout << mdt[n - 1][m - 1];
}