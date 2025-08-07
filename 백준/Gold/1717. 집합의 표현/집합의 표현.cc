#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int aa = Find(a);
	int bb = Find(b);

	if (aa > bb) parent[bb] = aa;
	else parent[aa] = bb;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;

	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> c >> a >> b;

		if (c) cout << (Find(a) == Find(b) ? "YES" : "NO") << '\n';
		else Union(a, b);
	}
}