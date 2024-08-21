#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    int i = 666;
    while (v.size() < n) {
        const string str = to_string(i);
        if (str.find("666") != string::npos)v.push_back(stoi(str));
        i++;
    }
    cout << v[n-1] << endl;
}