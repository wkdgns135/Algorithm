#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long X, K;
    cin >> X >> K;

    unordered_map<int, long long> left_count, right_count;

    // 왼발 양말 색상 개수 카운트
    for (int i = 0; i < X; i++)
    {
        int color;
        cin >> color;
        left_count[color]++;
    }

    // 오른발 양말 색상 개수 카운트
    for (int i = 0; i < X; i++)
    {
        int color;
        cin >> color;
        right_count[color]++;
    }

    // 전체 조합 수
    long long total_pairs = X * X;

    // 같은 색 양말 조합 제거
    for (const auto& pair : left_count)
    {
        int color = pair.first;
        if (right_count.count(color))
        {
            total_pairs -= pair.second * right_count[color];
        }
    }

    cout << total_pairs << '\n';
}
