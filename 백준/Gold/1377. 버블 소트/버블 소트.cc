#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    
    int maxVal = 0;
    for (int i = 0; i < N; i++) {
        maxVal = max(maxVal, A[i].second - i);
    }
    cout << maxVal + 1;
}
