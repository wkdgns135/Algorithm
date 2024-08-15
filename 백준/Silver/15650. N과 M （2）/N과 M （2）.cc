#include <bits/stdc++.h>
using namespace std;

int N, M;
void BackTracking(vector<int> v, vector<bool> isUsed, int n) {
	if (n == M) { for (int i = 0; i < M; i++)cout << v[i] << " "; cout << "\n"; return; }
	for (int i = 0; i < N; i++) {
		if (isUsed[i])continue;
		isUsed[i] = true;
		v[n] = i + 1;
		BackTracking(v, isUsed,n + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<int> v(M, 0);
	vector<bool> isUsed(N);
	BackTracking(v, isUsed, 0);
}