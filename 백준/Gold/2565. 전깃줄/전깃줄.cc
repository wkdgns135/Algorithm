#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	vector<int> dp(501);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		dp[v[i].second] = *max_element(dp.begin(), dp.begin() + v[i].second) + 1;
		answer = max(answer, dp[v[i].second]);
	}
	cout << n - answer;
}