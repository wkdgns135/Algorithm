#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<int, bool> dict;
    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        int n; cin >> n;
        if (!dict[n % 42])
        {
            dict[n % 42] = true;
            answer++;
        }
    }
    cout << answer;
}
