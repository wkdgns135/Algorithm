#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    vector<int> dp1(n - 1, 0); // 첫 번째 집을 털 경우
    vector<int> dp2(n, 0);     // 첫 번째 집을 털지 않는 경우

    // 첫 번째 집을 털 경우
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    }

    // 첫 번째 집을 털지 않는 경우
    dp2[0] = 0;
    dp2[1] = money[1];
    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
}