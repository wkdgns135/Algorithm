#include <bits/stdc++.h>
using namespace std;

vector<string> Split(string str) {
    vector<string> v;
    string temp = "";
    for (char& c : str) {
        if (c == '+' || c == '-') {
            v.push_back(temp);
            v.push_back(string(1,c));
            temp = "";
        }
        else temp += c;
    }
    v.push_back(temp);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    vector<string> v = Split(str);
    v.push_back("-");
    v.push_back("0");
    vector<int> nv;
    int n = 0;

    for (int i = 2; i < v.size(); i += 2) {
        if (v[i - 1] == "+") {
            n += stoi(v[i - 2]);
        }
        else if (v[i - 1] == "-") {
            n += stoi(v[i - 2]);
            nv.push_back(n);
            n = 0;
        }
    }
    for (int i = 1; i < nv.size(); i++) nv[0] -= nv[i];
    
    cout << nv[0];
}
