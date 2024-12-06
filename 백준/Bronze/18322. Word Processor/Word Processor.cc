#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K;
    cin >> N >> K;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    int currentLength = 0; // 현재 줄의 문자 길이 (공백 제외)
    for (int i = 0; i < N; i++) {
        int wordLength = words[i].size();

        if (currentLength == 0) {
            // 줄의 첫 단어는 바로 추가
            cout << words[i];
            currentLength += wordLength;
        }
        else if (currentLength + wordLength <= K) {
            // 현재 줄에 단어를 추가할 수 있으면 추가
            cout << " " << words[i];
            currentLength += wordLength; // 공백 + 단어 길이 추가
        }
        else {
            // 새 줄로 넘어가야 하는 경우
            cout << "\n" << words[i];
            currentLength = wordLength; // 새 줄에서의 단어 길이로 초기화
        }
    }

    cout << "\n"; // 마지막 줄 처리
}
