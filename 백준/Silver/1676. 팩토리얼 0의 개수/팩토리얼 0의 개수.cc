#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int count = 0;
    while (n > 1) {
        count+= n / 5;
        n /= 5;
    }
    cout << count;
}