#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	while (n--) {
		int num; cin >> num;
		if (maxHeap.empty()) {
			maxHeap.push(num);
		}
		else if (minHeap.empty()) {
			if (num < maxHeap.top()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(num);
			}
			else {
				minHeap.push(num);
			}
		}
		else if (num <= maxHeap.top()) {
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(num);
			}
			else {
				maxHeap.push(num);
			}
		}
		else if (num > maxHeap.top() && num < minHeap.top()) {
			if (maxHeap.size() > minHeap.size())minHeap.push(num);
			else maxHeap.push(num);
		}
		else if(num >= minHeap.top()){
			if (minHeap.size() > maxHeap.size()) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(num);
			}
			else {
				minHeap.push(num);
			}
		}
		if (maxHeap.size() > minHeap.size())cout << maxHeap.top() << '\n';
		if (maxHeap.size() < minHeap.size())cout << minHeap.top() << '\n';
		if (maxHeap.size() == minHeap.size())cout << min(maxHeap.top(), minHeap.top()) << '\n';
	}
}
