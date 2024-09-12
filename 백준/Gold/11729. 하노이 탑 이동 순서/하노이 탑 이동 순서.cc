#include<bits/stdc++.h>
using namespace std;

void hanoi(int depth, int from, int via, int to) {
    if (depth == 1) { cout << from << ' ' << to << '\n'; }
    else {
        hanoi(depth - 1, from, to, via);
        cout << from << ' ' << to << '\n';
        hanoi(depth - 1, via, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)cnt = (cnt * 2) + 1;
    cout << cnt << '\n';
    hanoi(n, 1, 2, 3);
}
