#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int left = 0, right = n - 1;
    int best_sum = INT_MAX;
    pair<int, int> result;

    while (left < right) {
        int sum = v[left] + v[right];

        if (abs(sum) < abs(best_sum)) {
            best_sum = sum;
            result = { v[left], v[right] };
        }

        // 합이 0보다 작으면 왼쪽 포인터를 증가시켜 합을 증가시킴
        if (sum < 0) left++;
        // 합이 0보다 크면 오른쪽 포인터를 감소시켜 합을 감소시킴
        else right--;
    }

    cout << result.first << ' ' << result.second << '\n';
    return 0;
}
