#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    vector<double> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    // 최댓값 M 찾기
    double maxScore = *max_element(scores.begin(), scores.end());

    // 새로운 점수 계산 후 평균 구하기
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i] / maxScore * 100;
    }

    double newAverage = sum / n;
    cout << fixed << setprecision(6) << newAverage;
}
