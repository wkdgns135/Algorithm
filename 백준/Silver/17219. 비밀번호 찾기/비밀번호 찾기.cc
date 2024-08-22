#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m; cin >> n >> m;
    unordered_map<string, string> map;
    string site;
    while (n--) { 
        string  pwd; cin >> site >> pwd;
        map[site] = pwd;
    }
    while (m--) { cin >> site; cout << map[site] << '\n'; }
}