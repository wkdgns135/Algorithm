#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    sort(str.begin(), str.end(), greater<>());
    cout << str;
}