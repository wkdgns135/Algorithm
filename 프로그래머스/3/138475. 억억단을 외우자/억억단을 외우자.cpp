#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> v(e + 1, 0); // 약수 개수를 세기 위해 크기 e+1로 초기화
    vector<int> E(e + 1, 0); // 약수 개수가 최대인 인덱스를 저장하기 위한 벡터

    // 1부터 e까지 각 수의 약수 개수 계산
    for(int i = 1; i <= e; i++) {
        for(int j = i; j <= e; j += i) {
            v[j]++;
        }
    }

    // e부터 1까지 역방향으로 순회하며 최대 약수 개수를 가진 인덱스 찾기
    int maxIndex = e;
    for(int i = e; i >= 1; i--) {
        if(v[i] >= v[maxIndex]) {
            maxIndex = i;
        }
        E[i] = maxIndex;
    }

    // 각 시작 위치에 대한 결과 저장
    for(int start : starts) {
        answer.push_back(E[start]);
    }

    return answer;
}
