#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    constexpr int SIZE = 1003001;
    vector<bool> prime(SIZE + 1);
    prime[1] = true;
    for (int i = 2; i < sqrt(SIZE); i++)
    {
        if (prime[i])continue;
        for (int j = i + i; j <= SIZE; j += i)
        {
            prime[j] = true;
        }
    }
    for (int i = n; i <= SIZE; i++)
    {
        if (prime[i])continue;
        string s = to_string(i);
        int left = 0, right = s.size() - 1;
        bool flag = true;
        while (left <= right)
        {
            if (s[left] != s[right])
            {
                flag = false;
                break;
            }
            left++, right--;
        }
        if (flag)
        {
            cout << i;
            return 0;
        }
    }
}
