#include <vector>
#include <iostream>
using namespace std;

void divide(int n, int N, int &answer) {
	if ((N - n) % 3 == 0) { answer += (N - n) / 3; return;}
	if (n < 1) {answer = -1; return;}
	divide(n - 5, N, --answer);
}

int main(void) {
	int n, answer = 0;
	cin >> n;
	answer = n / 5;
	divide(answer * 5, n, answer);
	cout << answer;
}