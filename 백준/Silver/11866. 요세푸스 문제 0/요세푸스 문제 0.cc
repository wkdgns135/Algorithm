#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K, index = 0;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++)v[i] = i + 1;
	cout << '<';
	while (true) {
		index = (index + K - 1) % v.size();
		cout << v[index];
		v.erase(v.begin() + index);
		if (v.empty())break;
		cout << ", ";
	}
	cout << '>';
	return 0;
}