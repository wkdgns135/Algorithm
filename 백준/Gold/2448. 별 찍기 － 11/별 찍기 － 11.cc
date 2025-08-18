#include <vector>
#include <iostream>
using namespace std;

void Fill(vector<vector<bool>>& v, int y, int x)
{
	v[y][x] = 1;
	v[y + 1][x - 1] = 1; v[y + 1][x + 1] = 1;
	for (int i = -2; i <= 2; i++) v[y + 2][x + i] = 1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int width = n * 2 - 1;
	vector<vector<bool>> v(n, vector<bool>(width));
	vector<vector<bool>> toggle(n, vector<bool>(width));

	auto Toggle = [&](int y, int x)
		{
			if (y < n && x < width && x >= 0 && y >= 0)
				toggle[y][x] = !toggle[y][x];
		};

	Fill(v, 0, n - 1);
	Toggle(3, n - 4);
	Toggle(3, n + 2);

	for (int i = 1; i < n / 3; i++)
	{
		int y = i * 3;
		for (int x = 0; x < width; x++)
		{
			if (!toggle[y][x]) continue;
			Fill(v, y, x);
			Toggle(y + 3, x - 3);
			Toggle(y + 3, x + 3);
		}
	}

	for (const auto& row : v)
	{
		for (bool col : row) cout << (col ? '*' : ' ');
		cout << '\n';
	}
}
