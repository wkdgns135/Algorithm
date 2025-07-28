#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n;

	vector<int> v1(n);
	for (int i = 0; i < n; i++) cin >> v1[i];

	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++) cin >> v2[i];

	sort(v1.begin(), v1.end());

	for (int num : v2)
	{
		int left = 0, right = n - 1;
		bool result = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (v1[mid] == num)
			{
				result = 1;
				break;
			}
			else if (v1[mid] < num)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		cout << result << ' ';
	}
}