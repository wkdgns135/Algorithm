#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	vector<int> v(302);
	for (int i = 1; i < 302; i++)
	{
		v[i] = v[i - 1] + i;
	}
	while (t--)
	{
		int n; cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += i * v[i + 1];
		}
		cout << sum << '\n';
	}
}
