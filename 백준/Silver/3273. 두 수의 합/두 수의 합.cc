#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int x, answer = 0; cin >> x;
    int left = 0, right = n - 1;

    while (left < right) {
        if (v[left] + v[right] == x) {
            answer++;
            left++;
        }
        else if (v[left] + v[right] > x) right--;
        else left++;
    }
    cout << answer;
}
