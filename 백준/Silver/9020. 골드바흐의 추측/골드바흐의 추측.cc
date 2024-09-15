#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int size = 10001;
    vector<bool> prime(10001, true);
    for (int i = 2; i < sqrt(10001); i++) {
        if (!prime[i])continue;
        for (int j = i + i; j < size; j += i) prime[j] = false;
    }

    while (t--) {
        int n; cin >> n;
        int left = n / 2, right = n / 2;

        while (true) {
            while (!prime[left])left--;
            while (!prime[right])right++;

            if (left + right == n)break;
            else if (left + right > n)left--;
            else if (left + right < n)right++;
        }
        cout << left << ' ' << right << '\n';
    }
}