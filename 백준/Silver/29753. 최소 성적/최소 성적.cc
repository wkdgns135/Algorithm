#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string x;
	cin >> n >> x;

	vector<pair<string, int>> dict = {
		{"F", 0}, {"D0", 100}, {"D+", 150}, {"C0", 200}, {"C+", 250},
		{"B0", 300}, {"B+", 350}, {"A0", 400}, {"A+", 450}
	};

	unordered_map<string, int> scoreMap;
	for (auto& [grade, score] : dict)
		scoreMap[grade] = score;

	int sumA = 0, sumB = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int a; string b;
		cin >> a >> b;
		sumA += a;
		sumB += scoreMap[b] * a;
	}
	int a; cin >> a;
	sumA += a;

	int i2 = (x[0] - '0') * 100 + (x[2] - '0') * 10 + (x[3] - '0');

	for (auto& [grade, score] : dict)
	{
		int i1 = (score * a + sumB) / sumA;
		if (i1 > i2)
		{
			cout << grade;
			return 0;
		}
	}
	cout << "impossible";
}
