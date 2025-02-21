#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int p, n; cin >> p >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int answer = 0;
	for (int i = 0; i < n && p < 200; i++)
	{
		p += v[i];
		answer++;
	}
	cout << answer;
}
