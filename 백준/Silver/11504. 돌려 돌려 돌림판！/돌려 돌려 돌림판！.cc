#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; // 테스트 케이스 수
    while (t--) {
        int N, M; // 돌림판 크기와 숫자의 자릿수
        cin >> N >> M;

        string X = "", Y = ""; // 범위의 최소값과 최대값
        for (int i = 0; i < M; ++i) {
            char digit; cin >> digit;
            X += digit;
        }
        for (int i = 0; i < M; ++i) {
            char digit; cin >> digit;
            Y += digit;
        }

        vector<int> wheel(N); // 돌림판 상태
        for (int i = 0; i < N; ++i) {
            cin >> wheel[i];
        }

        int count = 0; // 승리 가능한 경우의 수
        for (int start = 0; start < N; ++start) { // 돌림판의 각 시작점을 검사
            string Z = ""; // 현재 숫자 Z를 문자열로 생성
            for (int j = 0; j < M; ++j) {
                Z += to_string(wheel[(start + j) % N]);
            }

            // 범위 비교: X <= Z <= Y
            if (X <= Z && Z <= Y) {
                ++count;
            }
        }

        cout << count << '\n'; // 결과 출력
    }
}
