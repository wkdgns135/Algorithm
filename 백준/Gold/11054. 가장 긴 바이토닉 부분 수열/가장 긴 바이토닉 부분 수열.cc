#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> decrease(n , 1), increase(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j])decrease[i] = max(decrease[j] + 1, decrease[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j])increase[i] = max(increase[j] + 1, increase[i]);
        }
    }
    int answer = max(*max_element(increase.begin(), increase.end()), *max_element(decrease.begin(), decrease.end()));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j])answer = max(answer, increase[i] + decrease[j]);
        }
    }
    cout << answer;
}
