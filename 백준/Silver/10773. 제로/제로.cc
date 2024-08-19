#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int K;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> K;
    int n;
    stack<int> s;
    for (int i = 0; i < K; i++) {
        cin >> n;
        if (!n)s.pop();
        else s.push(n);
    }
    int sum = 0;
    while (!s.empty()) {
        sum += s.top(); s.pop();
    }
    cout << sum;
}