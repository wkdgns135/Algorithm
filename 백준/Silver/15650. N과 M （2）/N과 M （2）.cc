#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
void BackTracking(int depth, int index) {
	if (depth == M) { for (int i = 0; i < M; i++)cout << v[i] << " "; cout << "\n"; return; }
	for (int i = index; i < N; i++) {
		v[depth] = i + 1;
		BackTracking(depth + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	v = vector<int>(M, 0);
	BackTracking(0, 0);
}