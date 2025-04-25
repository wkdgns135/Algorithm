#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    constexpr static int N = 9;
    vector<int> v(N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N - 1; i++)
    {
        int compare = sum - v[i];
        for (int j = i + 1; j < N; j++)
        {
            if ((compare - v[j]) == 100)
            {
                for (int k = 0; k < N; k++)
                {
                    if (k == i || k == j)continue;
                    cout << v[k] << '\n';
                }
                return 0;
            }
        }
    }
}
