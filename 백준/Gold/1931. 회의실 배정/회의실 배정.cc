#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			if (a.second != b.second) return a.second < b.second;
			return a.first < b.first;
		});

	int pre = v[0].second;
	int answer = 1;

	for (int i = 1; i < n; i++)
	{
		if (pre <= v[i].first)
		{
			answer++;
			pre = v[i].second;
		}
	}
	cout << answer;
}