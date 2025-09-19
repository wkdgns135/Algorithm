#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	vector<long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	vector<long> result(3);
	result[0] = LONG_MAX;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int left = 0, right = n - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (abs(result[0] + result[1] + result[2]) > abs(v[i] + v[j] + v[mid]) && mid != i && mid != j)
				{
					result[0] = v[i], result[1] = v[j], result[2] = v[mid];
				}
				if (v[mid] + v[i] + v[j] < 0) left = mid + 1;
				else right = mid - 1;
			}
		}
	}

	sort(result.begin(), result.end());
	for (int num : result) cout << num << ' ';
}