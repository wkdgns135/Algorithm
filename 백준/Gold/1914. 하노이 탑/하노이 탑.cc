#include<bits/stdc++.h>
using namespace std;
int n;

void hanoi(int depth, const int &from, const int &via, const int &to) {
    if (depth == 1) { cout << from << ' ' << to << '\n'; }
    else {
        hanoi(depth - 1, from, to, via);
        cout << from << ' ' << to << '\n';
        hanoi(depth - 1, via, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string a = "1";
    for (int i = 1; i < n; i++) {
        string b = "";
        int carry = 0;
        while (!a.empty()) {
            int n1 = a.back() - '0';
            int n2 = a.back() - '0' + b.empty();
            a.pop_back();
            b.push_back((n1 + n2 + carry) % 10 + '0');
            carry = (n1 + n2 + carry) >= 10;
        }
        if (carry)b.push_back(carry + '0');
        reverse(b.begin(), b.end());
        a = b;
    }
    cout << a << '\n';
    const int from = 1, via = 2, to = 3;
    if(n < 21)hanoi(n, from, via, to);
}
