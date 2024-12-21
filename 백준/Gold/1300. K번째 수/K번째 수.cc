#include <bits/stdc++.h>
using namespace std;

long long func(long long n, long long x) {
    long long count = 0;
    for (int i = 1; i <= n; i++) {
        count += min(n, x / i);
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, k;
    cin >> n >> k;

    long long left = 1, right = n * n, answer = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (func(n, mid) >= k) {
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << answer << '\n';
}
