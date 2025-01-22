#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<deque<int>> v(4, deque<int>(8));
	for (int i = 0; i < 4; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++) {
			v[i][j] = s[j] - '0';
		}
	}
	int k; cin >> k;
	while (k--) {
		int N, R; cin >> N >> R;
		N--;
		stack<pair<int,int>> s;
		vector<bool> visited(4);
		s.push({N , R});
		visited[N] = true;
		while (!s.empty()) {
			int n, r; tie(n, r) = s.top();
			s.pop();
			visited[n] = true;
			if (n + 1 < 4 && !visited[n + 1]) {
				if (v[n][2] != v[n + 1][6]) {
					s.push({ n + 1, r * -1 });
				}
			}
			if (n - 1 >= 0 && !visited[n - 1]) {
				if (v[n][6] != v[n - 1][2]) {
					s.push({ n - 1, r * -1 });
				}
			}
			if (r == 1) {
				int tmp = v[n].back();
				v[n].pop_back();
				v[n].push_front(tmp);
			}
			else {
				int tmp = v[n].front();
				v[n].pop_front();
				v[n].push_back(tmp);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (v[i][0])answer += pow(2, i);
	}
	cout << answer;
}
