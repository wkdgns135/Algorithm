#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b; cin >> a >> b;

    unordered_map<int, bool> A, B;
    for (int i = 0; i < a; i++) {
        int num; cin >> num;
        A[num] = true;
    }
    for (int i = 0; i < b; i++) {
        int num; cin >> num;
        B[num] = true;
    }
    int answer = 0;
    for (auto& i : A) if (!B[i.first])answer++;
    for (auto& i : B) if (!A[i.first])answer++;
    
    cout << answer;
}
