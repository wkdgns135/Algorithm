#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	constexpr int SIZE = 110000;
	int n, k; cin >> n >> k;
	queue<int> bfs;
	bfs.push(n);
	vector<int> mdt(SIZE, INT_MAX);
	mdt[n] = 0;
	while (!bfs.empty())
	{
		int node = bfs.front();
		bfs.pop();
		if (node == k)break;
		if (node + 1 < SIZE && mdt[node + 1] > mdt[node] + 1)
		{
			bfs.push(node + 1);
			mdt[node + 1] = mdt[node] + 1;
		}
		if (node - 1 >= 0 && mdt[node - 1] > mdt[node] + 1)
		{
			bfs.push(node - 1);
			mdt[node - 1] = mdt[node] + 1;
		}
		if (node * 2 < SIZE && mdt[node * 2] > mdt[node] + 1)
		{
			bfs.push(node * 2);
			mdt[node * 2] = mdt[node] + 1;
		}
	}
	cout << mdt[k];
}
