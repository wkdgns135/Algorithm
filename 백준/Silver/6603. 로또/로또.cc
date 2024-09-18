#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> input, output(6);

void BackTracking(int depth, int index) {
    if (depth == 6) {
        for (auto& i : output) cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = index; i < n; i++) {
        output[depth] = input[i];
        BackTracking(depth + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> n; if (n == 0)break;
        input = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> input[i];
        BackTracking(0, 0);
        cout << '\n';
    }
}