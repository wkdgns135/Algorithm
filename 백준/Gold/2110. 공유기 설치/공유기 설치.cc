#include <bits/stdc++.h>
using namespace std;

bool canPlaceRouters(const vector<int>& houses, int distance, int c) {
    int count = 1;
    int lastPosition = houses[0]; 

    for (int i = 1; i < houses.size(); i++) {
        if (houses[i] - lastPosition >= distance) {
            count++;
            lastPosition = houses[i];
        }
        if (count >= c) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int left = 1;
    int right = houses[n - 1] - houses[0];
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canPlaceRouters(houses, mid, c)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';
}
