#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<string> stringArr(n);
	vector<long long> numArr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> stringArr[i];
		reverse(stringArr[i].begin(), stringArr[i].end());
		numArr[i] = stoll(stringArr[i]);
	}
	sort(numArr.begin(), numArr.end());
	for (const long long& num : numArr)
	{
		cout << num << '\n';
	}
}
