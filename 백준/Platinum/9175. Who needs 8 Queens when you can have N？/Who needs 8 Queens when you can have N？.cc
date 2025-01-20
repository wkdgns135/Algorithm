#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t, n, i; cin >> t;
	while (t--) {
		cin >> n;
		cout << n << '\n';
		if (n % 6 == 2) {
			for (i = 2; i <= n; i += 2) cout << i - 1 << ' ';
			cout << 2 << ' ' << 0 << ' ';
			for (i = 7; i <= n; i += 2) cout << i - 1 << ' ';
			cout << 4 << ' ';
		}
		else if (n % 6 == 3) {
			for (i = 4; i <= n; i += 2) cout << i - 1 << ' ';
			cout << 1 << ' ';
			for (i = 5; i <= n; i += 2) cout << i - 1 << ' ';
			cout << 0 << ' ' << 2 << ' ';
		}
		else {
			for (i = 2; i <= n; i += 2)cout << i - 1 << ' ';
			for (i = 1; i <= n; i += 2)cout << i - 1 << ' ';
		}
		cout << '\n';
	}
}
