#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    while (n--)
    {
        priority_queue<int> pq;
        for (int i = 0; i < 10; i++)
        {
            int num; cin >> num;
            pq.push(num);
        }
        for (int i = 0; i < 2; i++)pq.pop();
        cout << pq.top() << '\n';
    }
}