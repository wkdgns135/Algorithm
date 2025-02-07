#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string str; cin >> str;

	stack<char> s;
	int sum = 0, temp = 1;

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
			temp *= 2;
		}
		else if (str[i] == '[') {
			s.push('[');
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') sum += temp;
			s.pop();
			temp /= 2;
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') sum += temp;
			s.pop();
			temp /= 3;
		}
	}

	if (!s.empty()) {
		cout << 0;
		return 0;
	}

	cout << sum;
	return 0;
}
