#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int answer = 0, count = 0;
    for (int i = 1; i < m - 1; i++) {
        // IOI 패턴이 계속 이어질 때
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            count++;  // IOI 패턴 길이 카운트
            if (count == n) { // n번 반복되면 정답 증가
                answer++;
                count--;  // 패턴을 한 칸 앞으로 밀기 위해 감소
            }
            i++;  // IOI 패턴을 찾았으니 다음 I부터 탐색
        }
        else {
            count = 0;  // 패턴이 끊기면 초기화
        }
    }

    cout << answer;
}
