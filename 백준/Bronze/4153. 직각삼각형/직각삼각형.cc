#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break; // 입력 종료 조건

        int sides[] = { a, b, c };
        sort(sides, sides + 3);

        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }
    }
}
