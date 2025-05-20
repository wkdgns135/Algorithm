#include <iostream>
#include <iomanip>
using namespace std;

bool isRushHour(int hour, int minute) {
    // 오전 러시아워: 07:00 ~ 09:59
    if (hour >= 7 && hour < 10) return true;
    // 오후 러시아워: 15:00 ~ 18:59
    if (hour >= 15 && hour < 19) return true;
    return false;
}

int main() {
    string time;
    cin >> time;

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    double traveled = 0.0;

    while (traveled < 120.0) {
        // 러시아워면 절반만 이동
        if (isRushHour(hour, minute)) {
            traveled += 0.5;
        } else {
            traveled += 1.0;
        }

        // 다음 분으로 이동
        minute++;
        if (minute == 60) {
            minute = 0;
            hour = (hour + 1) % 24;
        }
    }

    // 출력
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << "\n";

    return 0;
}
