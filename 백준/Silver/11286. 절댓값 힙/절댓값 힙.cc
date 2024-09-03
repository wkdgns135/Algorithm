#include <bits/stdc++.h>
using namespace std;

struct Cmp{
    bool operator()(int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > b;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    priority_queue<int, vector<int>, Cmp> pq;
    while (n--) {
        int x; cin >> x;
        if (x)pq.push(x);
        else if(pq.empty())cout << "0" << '\n';
        else { cout << pq.top() << '\n'; pq.pop(); }
    }
}