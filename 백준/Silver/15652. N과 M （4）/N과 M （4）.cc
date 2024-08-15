#include <bits/stdc++.h>
using namespace std;

int N, M;
void BackTracking(vector<int> v, int n) {
	if (n == M) { for (int i = 0; i < M; i++)cout << v[i] << " "; cout << "\n"; return; }
	for (int i = 0; i < N; i++) {
		if (n > 0 && v[n - 1] > i + 1)continue;
		v[n] = i + 1;
		BackTracking(v, n + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<int> v(M, 0);
	BackTracking(v, 0);
}