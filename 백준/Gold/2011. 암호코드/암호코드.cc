#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string num; cin >> num;

    if (num[0] == '0') // 첫 번째 자리가 0이면 암호 해독 불가
    {
        cout << 0;
        return 0;
    }

    int n = num.size();
    vector<int> dp(n + 1);
    dp[0] = 1; // 아무것도 해석하지 않은 경우를 1로 둔다.
    dp[1] = 1; // 첫 번째 숫자는 무조건 한 가지 방법으로 해석 가능

    for (int i = 2; i <= n; i++)
    {
        int oneDigit = num[i - 1] - '0';       // 현재 한 자리 숫자
        int twoDigit = stoi(num.substr(i - 2, 2)); // 현재 두 자리 숫자

        if (oneDigit > 0)
            dp[i] = (dp[i] + dp[i - 1]) % 1000000;

        if (10 <= twoDigit && twoDigit <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
    }

    cout << dp[n];
}
