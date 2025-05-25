#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        set<char> digits;
        long long k = 0;

        while (digits.size() < 10) {
            ++k;
            long long val = n * k;
            string s = to_string(val);
            for (char c : s) {
                digits.insert(c);
            }
        }

        cout << k << endl;
    }
    return 0;
}
