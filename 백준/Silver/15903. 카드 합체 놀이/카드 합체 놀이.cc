#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        pq.push(x);
    }

    while (m--)
    {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long sum = a + b;
        pq.push(sum);
        pq.push(sum);
    }

    long long result = 0;
    while (!pq.empty())
    {
        result += pq.top();
        pq.pop();
    }

    cout << result;
}