#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end());

		int answer = n, minValue = v[0].second;
		for (int i = 1; i < n; i++)
		{
			if (minValue > v[i].second) minValue = v[i].second;
			else answer--;

		}
		cout << answer << '\n';
	}
}