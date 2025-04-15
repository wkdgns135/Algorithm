#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector<int> dict = { 3,2,1,	2,	4,	3,	1,	3,	1,	1,	3,	1,	3,	2,	1,	2,	2,	2,	1,	2,	1,	1,	1,	2,	2,	1 };
	vector<int> v;
	string a, b; cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (!a.empty() && !b.empty())
	{
		v.push_back(dict[a.back() - 'A']);
		v.push_back(dict[b.back() - 'A']);
		a.pop_back();
		b.pop_back();
	}
	while (!a.empty())
	{
		v.push_back(dict[a.back() - 'A']);
		a.pop_back();
	}
	while (!b.empty())
	{
		v.push_back(dict[b.back() - 'A']);
		b.pop_back();
	}
	for (int i = n + m - 1; i > 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			v[j] = v[j] + v[j + 1];
			v[j] %= 10;
		}
	}

	cout << (v[0] * 10) + v[1] << '%';
}