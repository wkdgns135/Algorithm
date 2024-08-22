#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int m; cin >> m;
    vector<int> v(21, 0);

    while (m--) {
        string command;
        int num;
        cin >> command;

        if (command == "add") { cin >> num; v[num] = 1; }
        else if (command == "check") { cin >> num; cout << v[num] << '\n'; }
        else if (command == "remove") { cin >> num; v[num] = 0;}
        else if (command == "toggle") { cin >> num; v[num] = !v[num];}
        else if (command == "all") fill(v.begin(), v.end(), 1);
        else if (command == "empty") fill(v.begin(), v.end(), 0);
    }
}