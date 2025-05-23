#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        double a, b, c;
        cin >> a >> b >> c;

        double discriminant = b * b - 4 * a * c;
        double sqrt_d = sqrt(discriminant);
        double x1 = (-b + sqrt_d) / (2 * a);
        double x2 = (-b - sqrt_d) / (2 * a);

        // 소수 셋째 자리까지 고정 출력
        cout << fixed << setprecision(3) << x1 << ", " << x2 << endl;
    }

    return 0;
}
