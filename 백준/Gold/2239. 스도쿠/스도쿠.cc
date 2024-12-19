#include <bits/stdc++.h>
using namespace std;

int v[9][9];
vector<pair<int, int>> empties;
bool flag = false;

bool Check(int x, int y, int n) {
	for (int i = 0; i < 9; i++)
		if (v[y][i] == n || v[i][x] == n)return false;
	int xx = x < 3 ? 0 : x < 6 ? 3 : 6;
	int yy = y < 3 ? 0 : y < 6 ? 3 : 6;
	for (int i = yy; i < yy + 3; i++) {
		for (int j = xx; j < xx + 3; j++) {
			if (v[i][j] == n)
				return false;
		}
	}
	return true;
}

int Count() {
	int sum = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			sum += v[i][j];
	return sum;
}

void Bt(int depth) {
	if (flag)return;
	if (depth == empties.size()) {
		flag = true;
		return;
	}

	auto pos = empties[depth];
	for (int i = 1; i <= 9; i++) {
		if (!Check(pos.second, pos.first, i))continue;
		v[pos.first][pos.second] = i;
		Bt(depth + 1);
		if (flag)break;
		v[pos.first][pos.second] = 0;
	}
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i < 9; i++) {
		string s; cin >> s;
		for (int j = 0; j < 9; j++) {
			v[i][j] = s[j] - '0';
			if (v[i][j] == 0)empties.push_back({ i, j });
		}
	}
	Bt(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
}