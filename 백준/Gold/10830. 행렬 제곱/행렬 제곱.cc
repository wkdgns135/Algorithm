#include <bits/stdc++.h>
using namespace std;

class Matrix : public vector<vector<int>> {
public:
	Matrix operator *(const Matrix& a) const {
		int n = size();
		Matrix result;
		result.resize(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					result[i][j] += at(i).at(k) * a[k][j];
				}
				result[i][j] %= 1000;
			}
		}
		return result;
	}
};

Matrix Power(Matrix m, long long b) {
	int n = m.size();
	Matrix result;
	result.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) result[i][i] = 1;

	while (b > 0) {
		if (b % 2 == 1) {
			result = result * m;
		}
		m = m * m;
		b >>= 1;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; long long b; cin >> n >> b;
	Matrix m; m.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	Matrix result = Power(m, b);
	for (const auto& row : result) {
		for (int val : row) cout << val << ' ';
		cout << '\n';
	}
}
