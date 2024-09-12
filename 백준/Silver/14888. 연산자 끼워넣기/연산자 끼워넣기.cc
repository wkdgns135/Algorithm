#include<bits/stdc++.h>
using namespace std;

int n, maxVal = INT_MIN, minVal = INT_MAX;
vector<int> v, oper;

void Bt(int depth, int value) {
    if (depth == n - 1) {
        maxVal = max(maxVal, value);
        minVal = min(minVal, value);
        return;
    }
    
    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] > 0) {
            int next = 0;
            switch (i)
            {
            case 0:
                next = value + v[depth + 1];
                break;
            case 1:
                next = value - v[depth + 1];
                break;
            case 2:
                next = value * v[depth + 1];
                break;
            case 3:
                next = value / v[depth + 1];
                break;
            }
            oper[i]--;
            Bt(depth + 1, next);
            oper[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v = vector<int>(n); for (int i = 0; i < n; i++)cin >> v[i];
    oper = vector<int>(4) ; for (int i = 0; i < 4; i++) cin >> oper[i];

    Bt(0, v[0]);

    cout << maxVal << '\n';
    cout << minVal << '\n';
}

