#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, input;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) { cin >> input; pq.push(input); }
	while (!pq.empty()){cout << pq.top() << "\n"; pq.pop();}
	return 0;
}