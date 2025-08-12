#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> house, chicken, temp;
int m, answer = INT_MAX;

int Calc()
{
	int sum = 0;
	for (auto& [y1, x1] : house)
	{
		int minVal = INT_MAX;
		for (int i = 0; i < m; i++)
		{
			auto& [y2, x2] = temp[i];
			minVal = min(abs(y1 - y2) + abs(x1 - x2), minVal);
		}
		sum += minVal;
	}
	return sum;
}

void BT(int depth, int index)
{
	if (depth == m)
	{
		answer = min(answer, Calc());
		return;
	}

	for (int i = index; i < chicken.size(); i++)
	{
		temp[depth] = chicken[i];
		BT(depth + 1, i + 1);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input; cin >> input;
			if (input == 1) house.push_back({ i, j });
			else if (input == 2) chicken.push_back({ i, j });
		}
	}
	temp.resize(m);

	BT(0, 0);
	cout << answer;
}