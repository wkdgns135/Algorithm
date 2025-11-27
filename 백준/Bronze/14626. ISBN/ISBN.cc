#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;

	int sum = 0;
	bool flag = true;
	for (int i = 0; i < 12; i++)
	{
		if (s[i] != '*')
		{
			int num = s[i] - '0';

			if (i % 2 == 0) sum += num;
			else sum += num * 3;
		}
		else
		{
			flag = i % 2 == 0;
		}
	}

	int m = s[12] - '0';
	for (int i = 0; i < 10; i++)
	{
		int n = flag ? i : i * 3;
		int pred = (10 - ((sum + n) % 10));
		if (m == pred || (pred == 10 && m == 0)) cout << i;
	}
}