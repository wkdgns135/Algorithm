#include <iostream>
using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    while (true) {
        int d, m, y;
        cin >> d >> m >> y;

        if (d == 0 && m == 0 && y == 0) break;

        int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap(y)) month_days[1] = 29;

        int total = 0;
        for (int i = 0; i < m - 1; ++i)
            total += month_days[i];
        total += d;

        cout << total << '\n';
    }
    return 0;
}
