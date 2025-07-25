#include <bits/stdc++.h>
using namespace std;

void DC(vector<string>& quad, int x, int y, int size)
{
	int sum = 0;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			sum += quad[i][j] - '0';
		}
	}

	if (sum == size * size || sum == 0)
	{
		cout << quad[y][x];
		return;
	}

	cout << '(';
	for (int i = 0; i < 4; i++)
	{
		int xx = x + (i % 2) * (size / 2);
		int yy = y + (i / 2) * (size / 2);
		DC(quad, xx, yy, size / 2);
	}
	cout << ')';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	vector<string> quad(n);
	for (int i = 0; i < n; i++)cin >> quad[i];

	DC(quad, 0, 0, n);
}