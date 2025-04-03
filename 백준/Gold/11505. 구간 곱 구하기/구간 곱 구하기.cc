#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

vector<long long> tree, arr;

long long MakeTree(int start, int end, int node)
{
    if (start == end) return tree[node] = arr[start] % MOD;
    int mid = (start + end) / 2;
    return tree[node] = (MakeTree(start, mid, node * 2) * MakeTree(mid + 1, end, node * 2 + 1)) % MOD;
}

long long Query(int start, int end, int node, int left, int right)
{
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return (Query(start, mid, node * 2, left, right) * Query(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

void Update(int start, int end, int node, int index, long long newValue)
{
    if (index < start || index > end) return;
    if (start == end)
    {
        tree[node] = newValue % MOD;
        return;
    }
    int mid = (start + end) / 2;
    Update(start, mid, node * 2, index, newValue);
    Update(mid + 1, end, node * 2 + 1, index, newValue);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    tree.resize(n * 4), arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MakeTree(0, n - 1, 1);

    for (int i = 0; i < m + k; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1)
        {  
            Update(0, n - 1, 1, b - 1, c);
            arr[b - 1] = c;
        }
        else
        { 
            cout << Query(0, n - 1, 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
