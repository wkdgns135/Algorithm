#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> q;
	int N, input;
	string command;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") { cin >> input; q.push(input); }
		else if (command == "top")cout << (q.empty() ? -1 : q.top()) << "\n";
		else if (command == "size")cout << q.size() << "\n";
		else if (command == "empty")cout << q.empty() << "\n";
		else if (command == "pop") {
			if (q.empty())cout << -1 << "\n";
			else {cout << q.top() << "\n"; q.pop();}
		}
	}
	return 0;
}