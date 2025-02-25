#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), P(N);
    vector<pair<int, int>> AWithIndex(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        AWithIndex[i] = {A[i], i}; 
    }

    sort(AWithIndex.begin(), AWithIndex.end());

    for (int i = 0; i < N; i++) {
        P[AWithIndex[i].second] = i; 
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << '\n';

    return 0;
}
