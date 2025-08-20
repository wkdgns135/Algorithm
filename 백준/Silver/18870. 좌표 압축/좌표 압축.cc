#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	vector<int> v1(n), v2(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
		v2[i] = v1[i];
	}

	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());

	for (int i : v2) cout << lower_bound(v1.begin(), v1.end(), i) - v1.begin() << ' ';
}