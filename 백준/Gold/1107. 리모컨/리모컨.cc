#include <bits/stdc++.h>
using namespace std;

bool CheckNum(int num, vector<bool> &nums) {
    for (char& c : to_string(num)) if (!nums[c - '0'])return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<bool> nums(10, true); 
    for (int i = 0; i < m; i++) {
        int input; cin >> input;
        nums[input] = false;
    }
    
    int left = n, right = n, near = 100;

    for (int i = n; i >= 0; i--) {
        if (CheckNum(i, nums)) {
            if (abs(n - near) > abs(n - i))near = i;
            break;
        }
    }

    for (int i = n; i <= max(n * 2, 100); i++) {
        if (CheckNum(i, nums)) {
            if (abs(n - near) > abs(n - i))near = i;
            break;
        }
    }
    int log = near == 0 ? 1 : floor(log10(near)) + 1;
    cout << min(abs(n - 100), abs(n - near) + log);
}
