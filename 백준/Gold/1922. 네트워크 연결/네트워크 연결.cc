#include <bits/stdc++.h>
using namespace std;

vector<int> unf;
int Find(int a) {
    if (a == unf[a])return a;
    return unf[a] = Find(unf[a]);
}
bool Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);
    if (aa != bb) {
        unf[aa] = bb;
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e; cin >> v >> e;
    priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    unf = vector<int>(v + 1);
    for (int i = 1; i <= v; i++)unf[i] = i;
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        pq.push({ c, a, b });
    }
    int answer = 0;
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        int a = get<1>(edge), b = get<2>(edge);
        if (Union(a, b)) answer += get<0>(edge);
    }
    cout << answer;
}