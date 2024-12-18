#include <bits/stdc++.h>
using namespace std;

bool Move(int &x, int &y, int dir, int n, int m) {
	int offset[4][2] = { {0,1},{-1, 0},{0,-1},{1,0} };
	
	int xx = x + offset[dir][1] * n;
	int yy = y + offset[dir][0] * n;
	if (xx < 0 || xx >= m || yy < 0 || yy >= m)return false;
	x = xx;
	y = yy;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, n; cin >> m >> n;

	int x = 0, y = 0, dir = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int num; cin >> num;
		if (s == "MOVE") {
			if (!Move(x, y, dir, num, m)) {
				cout << "-1";
				return 0;
			}
		}
		if (s == "TURN") dir = num ? (dir + 1) % 4 : (dir + 3) % 4;
	}
	cout << x << ' ' << y;
}