#include <iostream>
using namespace std;

bool isSquareFree(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % (i * i) == 0) return false; // i^2 divides x
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int m = 2; m < n; ++m) {
        if (isSquareFree(n * m)) {
            cout << m << endl;
            return 0;
        }
    }
}
