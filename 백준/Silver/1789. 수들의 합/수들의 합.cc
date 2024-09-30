#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long s; cin >> s;
    long long pre = 0;
    for (int i = 1; ; i++) {
        long long sum = pre + i;
        if (sum > s) {
            cout << i - 1;
            break;
        }
        pre = sum;
    }
}