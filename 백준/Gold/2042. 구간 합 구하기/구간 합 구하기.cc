#include <bits/stdc++.h>
using namespace std;

vector<long long> tree, v;

long long MakeTree(int start, int end, int node) {
	if (start == end) return tree[node] = v[start];
	int mid = (start + end) >> 1;
	int next = node << 1;
	return tree[node] = MakeTree(start, mid, next) + MakeTree(mid + 1, end, next + 1);
}

long long Sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) >> 1;
	int next = node << 1;
	return Sum(start, mid, next, left, right) + Sum(mid + 1, end, next + 1, left, right);
}

void Update(int start, int end, int node, int target, long long diff) {
	if (target < start || target > end)return;
	tree[node] += diff;
	if (start == end)return;
	int mid = (start + end) >> 1;
	int next = node << 1;
	Update(start, mid, next, target, diff);
	Update(mid + 1, end, next + 1, target, diff);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	tree.resize(n * 4);
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	MakeTree(0, n - 1, 1);
	for (int i = 0; i < m + k; i++) {
		int a, b; cin >> a >> b;
		long long c; cin >> c;
		if (a == 1) {
			long long diff = c - v[b - 1];
			v[b - 1] = c;
			Update(0, n - 1, 1, b - 1, diff);
		}
		else cout << Sum(0, n - 1, 1, b - 1, c - 1) << '\n';
	}
}
