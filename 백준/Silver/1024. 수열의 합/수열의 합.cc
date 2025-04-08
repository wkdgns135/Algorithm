#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    long long N;
    int L;
    cin >> N >> L;

    for (int len = L; len <= 100; ++len)
    {
        long long temp = (long long)len * (len - 1) / 2;
        if (N < temp) break;

        if ((N - temp) % len != 0) continue;

        long long x = (N - temp) / len;
        if (x < 0) continue;

        for (int i = 0; i < len; ++i)
        {
            cout << (x + i) << " ";
        }
        cout << "\n";
        return 0;
    }

    cout << "-1\n";
}
