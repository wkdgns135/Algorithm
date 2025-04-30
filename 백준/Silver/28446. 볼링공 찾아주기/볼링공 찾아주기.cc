#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int M;
	cin >> M;

	unordered_map<long long, int> ball_to_locker;

	for (int i = 0; i < M; ++i)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			int x;
			long long w;
			cin >> x >> w;
			ball_to_locker[w] = x;
		}
		else if (cmd == 2)
		{
			long long w;
			cin >> w;
			cout << ball_to_locker[w] << '\n';
		}
	}
}
