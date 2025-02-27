#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    vector<int> arr(n);
    long long sum = 0, square_sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        square_sum += 1LL * arr[i] * arr[i];
    }

    long long result = (sum * sum - square_sum) / 2;
    cout << result << '\n';

    return 0;
}
