#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	if (n <= 5)
	{
		cout << n;
		return 0;
	}
	int arr[8] = { 4,3,2,1,2,3,4,5 };
	cout << arr[(n - 6) % 8] << '\n';
}
