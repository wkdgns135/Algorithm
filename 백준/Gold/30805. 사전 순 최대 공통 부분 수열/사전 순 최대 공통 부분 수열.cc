#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // 입력 처리
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    // 최대값 계산
    int mx = max(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()));

    // 결과 저장
    vector<int> ans;

    // 최대값부터 1까지 반복
    for (int i = mx; i > 0; i--) {
        while (true) {
            // i가 a와 b에 없으면 종료
            auto it_a = find(a.begin(), a.end(), i);
            auto it_b = find(b.begin(), b.end(), i);
            if (it_a == a.end() || it_b == b.end()) break;

            // 공통 원소를 결과에 추가
            ans.push_back(i);

            // a와 b를 자른 뒤 계속 탐색
            a.erase(a.begin(), it_a + 1);
            b.erase(b.begin(), it_b + 1);
        }
    }

    // 결과 출력
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}
