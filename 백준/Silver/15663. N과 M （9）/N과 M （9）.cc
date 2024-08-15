#include <bits/stdc++.h>
using namespace std;

int N, M;

void BackTracking(vector<int> v1, vector<int> v2, vector<bool> v3, set<vector<int>> &s, int n) {
	if (n == M) { s.insert(v2); return; }
	for (int i = 0; i < N; i++) {
		if (v3[i])continue;
		v3[i] = true;
		v2[n] = v1[i];
		BackTracking(v1, v2, v3, s, n + 1);
		v3[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<int> v1(N),v2(M);
	vector<bool> v3(N);
	set<vector<int>> s;

	for (int i = 0; i < N; i++)cin >> v1[i];
	sort(v1.begin(), v1.end());
	BackTracking(v1, v2, v3, s, 0);

	for (auto i : s) { for (auto j : i)cout << j << " "; cout << "\n"; }
}