#include <bits/stdc++.h>
using namespace std;

int n, m, x; 
int FindShortcut(vector<vector<pair<int, int>>> &v, int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> mdt(n, INT_MAX);
	
	pq.push({ 0, start });
	mdt[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (cost != mdt[node])continue;
		for (auto &edge : v[node]) {
			if (mdt[edge.first] > edge.second + cost) {
				mdt[edge.first] = edge.second + cost;
				pq.push({ mdt[edge.first], edge.first });
			}
		}
	}
	return mdt[end];
}

int main() {
	cin >> n >> m >> x; x--;
	vector<vector<pair<int, int>>> v(n);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		v[a].push_back({ b, c });
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (i == x)continue;
		answer = max(FindShortcut(v, i, x) + FindShortcut(v, x, i), answer);
	}
	cout << answer;
}