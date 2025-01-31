#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int left = 0, right = n - 1;
	int minLeft = left, minRight = right;

	while (left < right) {
		if (abs(v[left] + v[right]) < abs(v[minLeft] + v[minRight])) {
			minLeft = left, minRight = right;
		}
		if (v[left] + v[right] > 0)right--;
		else if (v[left] + v[right] < 0)left++;
		else break;
	}
	cout << v[minLeft] << ' ' << v[minRight];
}
