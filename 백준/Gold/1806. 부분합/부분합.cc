#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, s; cin >> n >> s;
    vector<int> v(n); 
    for (int i = 0; i < n; i++) cin >> v[i];

    int left = 0, right = 0, sum = 0, length = INT_MAX;
    while (right < n) {
        sum += v[right];
        right++;

        while (sum >= s) {
            length = min(length, right - left);
            sum -= v[left];
            left++;
        }
    }
    cout << (length == INT_MAX ? 0 : length);
}
