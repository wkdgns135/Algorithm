#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<bool>> v(100, vector<bool>(100));
    
    while (n--) {
        int a, b; cin >> a >> b;
        a--, b--;
        for (int i = a; i < a + 10; i++) for (int j = b; j < b + 10; j++) v[i][j] = true;
    }
    
    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            answer += v[i][j];
        }
    }
    cout << answer;
}
