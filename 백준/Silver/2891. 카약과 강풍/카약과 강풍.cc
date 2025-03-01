#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, s, r; cin >> n >> s >> r;
	vector<int> v(n + 2, 1);
	for (int i = 0; i < s; i++)
	{
		int input; cin >> input;
		v[input]--;
	}
	for (int i = 0; i < r; i++)
	{
		int input; cin >> input;
		v[input]++;
	}

	int answer = 0;
	for (int i = 0; i <= n; i++)
	{
		if (v[i] == 0)
		{
			if (v[i - 1] == 2)
			{
				v[i - 1]--;
				v[i]++;
			}
			else if (v[i + 1] == 2)
			{
				v[i + 1]--;
				v[i]++;
			}
			answer += v[i] == 0;
		}
	}
	cout << answer;
}
