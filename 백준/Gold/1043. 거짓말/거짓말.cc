#include <vector>
#include <iostream>
using namespace std;

vector<int> parent, truth, depth;

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int aa = Find(a);
	int bb = Find(b);

	if (depth[aa] > depth[bb]) parent[bb] = aa;
	else
	{
		parent[aa] = bb;
		if (depth[aa] == depth[bb]) depth[bb]++;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;

	int t; cin >> t;
	truth.resize(n + 1);
	parent.resize(n + 1);
	depth.resize(n + 1);

	for (int i = 0; i < t; i++)
	{
		int idx; cin >> idx;
		truth[idx] = 1;
	}
	for (int i = 1; i <= n; i++) parent[i] = i;

	vector<vector<int>> v(m);

	for (int i = 0; i < m; i++)
	{
		int input; cin >> input;
		v[i].resize(input);
		for (int j = 0; j < input; j++) cin >> v[i][j];

		for (int j = 1; j < input; j++)
		{
			Union(v[i][0], v[i][j]);
		}
	}

    for (int i = 1; i <= n; i++) if (truth[i]) truth[Find(i)] = 1;

    for (auto& row : v)
    {
        for (int i : row)
        {
            if (truth[Find(i)])
            {
                m--; break;
            }
        }
    }
	cout << m;
}