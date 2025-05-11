#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
    int P;
    cin >> P;
    while (P--)
    {
        int K, N;
        cin >> K >> N;
        int S1 = N * (N + 1) / 2;
        int S2 = N * N;
        int S3 = N * (N + 1);
        cout << K << ' ' << S1 << ' ' << S2 << ' ' << S3 << '\n';
    }
}
