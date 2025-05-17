#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int n = s.size();
	int answer = 0;
	for (int i = n / 2; i >= 1; i--)
	{
		for (int j = 0; j <= n - i * 2; j++)
		{
			int left = 0, right = 0;
			for (int k = j; k < j + i; k++)left += s[k];
			for (int k = j + i; k < j + i * 2; k++)right += s[k];
			if (left == right)
			{
				cout << i * 2;
				return 0;
			}
		}
	}
}