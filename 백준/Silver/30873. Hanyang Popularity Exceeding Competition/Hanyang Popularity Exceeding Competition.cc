#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int x = 0;
	while (n--) {
		int p, c; cin >> p >> c;
		if (abs(p - x) <= c)x++;
	}
	cout << x;
}