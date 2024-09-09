#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k, n; cin >> k >> n;
    long long right = 0, left = 0;
    vector<int> v(k); for (int i = 0; i < k; i++) { cin >> v[i]; if (right < v[i])right = v[i]; };
    right += 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += v[i] / mid;
        }
        if (count < n) right = mid;
        else left = mid + 1;
    }
    cout << left - 1;
}
