#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<bool> prime(1000000, true);
	for (int i = 2; i < 1000; i++) {
		if (!prime[i])continue;
		for (int j = i + i; j < 1000000; j += i) {
			prime[j] = false;
		}
	}
	while (n) {
		int left = 2, right = n;
		cout << n << " = ";
		while ((left + right) != n) {
			if (left + right > n)
			{
				do { right--; } while (!prime[right]);
			}
			else if (left + right < n)
			{
				do { left++; } while (!prime[left]);
			}
		}
		cout << left << " + " << right << '\n';
		cin >> n;
	}
}
