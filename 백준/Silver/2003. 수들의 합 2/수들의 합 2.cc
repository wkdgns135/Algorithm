#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	int answer = 0;
	vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n && sum <= m; j++) {
			sum += v[j];
			if (sum == m)answer++;
		}
	}
	cout << answer;
}