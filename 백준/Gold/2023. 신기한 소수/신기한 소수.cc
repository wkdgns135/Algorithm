#include <bits/stdc++.h>
using namespace std;

int n;
string s = "";

bool IsPrime(int num)
{
    if (num < 2)return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)return false;
    }
    return true;
}

void BackTacking(int depth)
{
    if (depth == n)
    {
        cout << s << '\n';
        return;
    }
    for (char i = '1'; i <= '9'; i++)
    {
        s += i;
        if (IsPrime(stoi(s)))
        {
            BackTacking(depth + 1);
        }
        s.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    BackTacking(0);
}
