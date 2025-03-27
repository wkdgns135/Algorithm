#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, answer;

void BackTracking(int depth, int limit)
{
    if (n == 0)return;
    if (depth == limit)
    {
        n--;
        if (n == 0)
        {
            answer = v;
        }
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (depth == 0 || v[depth - 1] > i)
        {
            v[depth] = i;
            BackTracking(depth + 1, limit);
            v[depth] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    n++;

    for (int i = 0; i <= 9; i++)
    {
        v.resize(i + 1);
        BackTracking(0, i + 1);
    }

    if (answer.empty()) cout << -1;
    else
    {
        for (const int& num : answer)
        {
            cout << num;
        }
    }
}