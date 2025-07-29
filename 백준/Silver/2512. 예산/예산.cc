#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n;
	vector<int> v(n);
	int left = 0, right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		right = max(v[i], right);
	}

	cin >> m;
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		long long sum = 0;
		for (int i : v) sum += min(i, mid);

		if (sum <= m)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << answer;
}