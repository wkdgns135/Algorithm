#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void bt(int depth, int index)
{
	if (depth == m)
	{
		for (int& i : v) cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = index; i < n; i++)
	{
		v[depth] = i + 1;
		bt(depth + 1, i);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	v.resize(m);
	bt(0, 0);
}
