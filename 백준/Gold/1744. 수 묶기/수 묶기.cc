#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int left = 0, right = n - 1, sum = 0;
	if (n == 1)
	{
		cout << v[0];
		return 0;
	}
	while (left <= right)
	{
		vector<int> temp;
		if (right - left > 1)temp.insert(temp.end(), { v[left],v[right] ,v[left] * v[left + 1], v[right] * v[right - 1] });
		else if (right - left == 1)temp.insert(temp.end(), { v[left] * v[right], v[left] + v[right] });
		else
		{
			sum += v[left];
			break;
		}
		int maxVal = *max_element(temp.begin(), temp.end());
		if (maxVal == v[left] && right - left > 1) left++;
		else if (maxVal == v[right] && right - left > 1) right--;
		else if (maxVal == v[right] * v[right - 1]) right -= 2;
		else if (maxVal == v[left] * v[left + 1])left += 2;
		else if (maxVal == v[left] * v[right])right -= 2;
		else if (maxVal == v[left] + v[right])right -= 2;
		sum += maxVal;
	}
	cout << sum;
}
