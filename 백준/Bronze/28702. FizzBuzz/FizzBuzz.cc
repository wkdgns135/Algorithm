#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> v(3);
    int index = 0, num = 0;
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
        if (v[i][0] < 'A') {
            index = i;
            num = stoi(v[i]);
        }
    }
    num = (3 - index) + num;
    if (num % 3 == 0 && num % 5 == 0)cout << "FizzBuzz";
    else if (num % 3 == 0) cout << "Fizz";
    else if (num % 5 == 0) cout << "Buzz";
    else cout << num;
}
