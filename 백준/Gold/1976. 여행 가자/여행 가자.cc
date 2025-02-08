#include <bits/stdc++.h>
using namespace std;

vector<int> parent, target;
int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	parent.resize(n);
	target.resize(m);
	for(int i = 0; i < n; i++)parent[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			if (num == 1) {
				Union(i, j);
			}
		}
	}

	for(int i = 0; i < m; i++)cin >> target[i];
	cout << (any_of(target.begin(), target.end(), [](const int& x) {
		return parent[target[0] - 1] != parent[x - 1];
		}) ? "NO" : "YES");
}
