#include <bits/stdc++.h>
using namespace std;

void func(vector<int> &nodes, int s, int e) {
	if (s >= e)return;
	int i;
	for (i = s + 1; i < e; i++) if (nodes[s] < nodes[i])break;
	func(nodes, s + 1, i);
	func(nodes, i, e);
	cout << nodes[s] << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int> nodes;
	int n;
	while (cin >> n) nodes.push_back(n);
	func(nodes, 0, nodes.size());
}