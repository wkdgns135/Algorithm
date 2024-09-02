#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        multiset<int> ms;

        while (k--) {
            char c; cin >> c;
            int n; cin >> n;
            if (c == 'I') {
                ms.insert(n);  // 삽입 작업은 O(log k)
                }
                else {
                    if (!ms.empty()) {
                        if (n == 1) {
                            auto it = ms.end();
                            --it;  // 가장 큰 요소에 대한 iterator
                            ms.erase(it);  // 가장 큰 요소 제거, O(log k)
                        }
                        else {
                            ms.erase(ms.begin());  // 가장 작은 요소 제거, O(log k)
                        }
                    }
                }
            }
            if (ms.empty()) {
                cout << "EMPTY" << '\n';
            }
            else {
                auto min_it = ms.begin();  // 가장 작은 요소
                auto max_it = ms.end();
                --max_it;  // 가장 큰 요소
                cout << *max_it << ' ' << *min_it << '\n';
        }
    }
}
