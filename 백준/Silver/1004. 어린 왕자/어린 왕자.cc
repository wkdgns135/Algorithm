#include <bits/stdc++.h>
using namespace std;

float Distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool InCircle(int x1, int y1, int x2, int y2, int r) {
	return Distance(x1, y1, x2, y2) <= r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t, n, x1, y1, x2, y2, cx, cy, r;
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		int answer = 0;
		while (n--) {
			cin >> cx >> cy >> r;
			answer += InCircle(cx, cy, x1, y1, r) != InCircle(cx, cy, x2, y2, r);
		}
		cout << answer << '\n';
	}
}
