#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int sum = 0;
    queue<int> q;
    for (int i = 0; i < x; i++) {
        q.push(v[i]);
        sum += v[i];
    }

    int count = 1;
    int answer = sum;
    for (int i = x; i < n; i++) {
        sum -= q.front(), q.pop();
        sum += v[i];
        q.push(v[i]);
        if (sum > answer) {
            answer = sum;
            count = 1;
        }
        else if (sum == answer)count++;
    }
    if (answer == 0)cout << "SAD";
    else {
        cout << answer << '\n' << count;
    }
}