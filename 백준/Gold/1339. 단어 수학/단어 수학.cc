#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> dict;
vector<string> v;

int Calc() {
	int sum = 0;
	for (string s : v) {
		for (char &c : s) {
			c = dict[c] + '0';
		}
		sum += stoi(s);
	}
	return sum;
}

void BT(int depth) {
	if (depth == dict.size()) {
		cout << Calc();
		return;
	}
	
	int maxVal = 0;
	char c = ' ';
	for (auto &i : dict) {
		if (i.second != 0)continue;
		i.second = 9 - depth;
		if (maxVal < Calc()) {
			maxVal = Calc();
			c = i.first;
		}
		i.second = 0;
	}
	dict[c] = 9 - depth;
	BT(depth + 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v[i] = s;
		for (const char& c : s) {
			dict[c] = 0;
		}
	}
	BT(0);
}
