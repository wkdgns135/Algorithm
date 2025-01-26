#include <bits/stdc++.h>
using namespace std;

int n, answer = 0;
vector<bool> visited;

void bt(int depth, int index, int sum, vector<int>& v) {
	if (depth == n) {
		answer = max(sum, answer);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i])continue;
		visited[i] = true;
		bt(depth + 1, i, sum + abs(v[index] - v[i]), v);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<int> v(n);
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		visited[i] = true;
		bt(1, i, 0, v);
		visited[i] = false;
	}
	cout << answer;
}