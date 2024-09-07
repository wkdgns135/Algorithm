#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<bool> v(10036, true);

    for (int i = 1; i < 10000; i++) {
        int n = i;
        string str = to_string(i);
        for (int j = 0; j < str.size(); j++) n += str[j] - '0';
        v[n] = false;
    }

    for (int i = 1; i < 10000; i++) {
        if (v[i])cout << i << '\n';
    }
}