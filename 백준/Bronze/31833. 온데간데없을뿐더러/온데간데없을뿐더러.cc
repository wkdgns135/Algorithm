#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n; cin >> n;
	string a, b;
	for (int i = 0; i < n; i++)
	{
		string input; cin >> input;
		a.append(input);
	}
	for (int i = 0; i < n; i++)
	{
		string input; cin >> input;
		b.append(input);
	}
	if (stoll(a) < stoll(b))cout << a;
	else cout << b;
}