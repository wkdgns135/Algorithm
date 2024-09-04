#include <iostream>
using namespace std;

int main() {
	double a, b;
	while (true) {
		cin >> a >> b;
		if (0 < a || b < 10) {
			break;
		}
		else {
			continue;
		}
	}
	cout.precision(15);
	cout << a / b << endl;
	return 0;
}