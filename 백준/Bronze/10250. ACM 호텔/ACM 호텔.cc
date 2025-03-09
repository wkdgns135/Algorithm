#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int h, w, n; cin >> h >> w >> n;
		int floor = (n % h == 0) ? h : n % h;
		int room = (n + h - 1) / h;
		cout << floor << setw(2) << setfill('0') << room << '\n';
		
	}
}