#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<string>> v(n , vector<string>(m));
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> v[i][j];
	
	bool flag = true;
	int maxCnt = 0, maxIdx = 0, answer = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			for (char& c : v[i][j]) {
				if (c == '9')cnt++;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
			maxIdx = i;
			flag = true;
		}
		answer += cnt;
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			for (char& c : v[j][i]) {
				if (c == '9')cnt++;
			}
		}
		if (maxCnt < cnt) {
			maxCnt = cnt;
			maxIdx = i;
			flag = false;
		}
	}

	if (flag) {
		for (int i = 0; i < m; i++) {
			for (char& c : v[maxIdx][i]) {
				if (c == '9')answer--;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (char& c : v[i][maxIdx]) {
				if (c == '9')answer--;
			}
		}
	}
	cout << answer;
}