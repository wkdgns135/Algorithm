#include <bits/stdc++.h>

using namespace std;

int N;

struct Compare {
    bool operator() (pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
        if (a.first.first != b.first.first) return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    vector<pair<pair<int, int>, string>> v;

    cin >> N;
    while (N--) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({ { age, N }, name });
    }

    sort(v.begin(), v.end(), Compare());
    for(auto i : v)cout << i.first.first << ' ' << i.second << '\n';
}