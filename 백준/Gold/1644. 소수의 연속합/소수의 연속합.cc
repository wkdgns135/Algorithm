#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<bool> isPrime(n + 1, true);
	vector<int> prime;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = i + i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
	int left = 0, right = 0, sum = 2;
	int answer = 0;
	while (left < prime.size() && right < prime.size()) {
		if (sum < n) {
			right++;
			if (right < prime.size()) sum += prime[right];
		}
		else if (sum > n) {
			sum -= prime[left];
			left++;
		}
		else if (sum == n) {
			sum -= prime[left];
			left++;
			answer++;
		}
	}
	cout << answer;
}
