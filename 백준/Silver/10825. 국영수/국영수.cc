#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<tuple<int, int, int, string>> v(n);
	for (int i = 0; i < n; i++)
		cin >> get<3>(v[i]) >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);
	sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
		if (get<0>(a) != get<0>(b))return get<0>(a) > get<0>(b);
		if (get<1>(a) != get<1>(b))return get<1>(a) < get<1>(b);
		if (get<2>(a) != get<2>(b))return get<2>(a) > get<2>(b);
		return get<3>(a) < get<3>(b);
		});
	for (const auto& i : v)cout << get<3>(i) << '\n';
}
