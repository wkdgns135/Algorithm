#include <bits/stdc++.h>
using namespace std;

int n, l;

bool checkRow(vector<vector<int>>& v, int s, int e, int row, bool isRow)
{
    vector<bool> placed(n, false); // 경사로 설치 여부
    int prev = isRow ? v[row][s] : v[s][row], cnt = 1;

    for (int i = s + 1; i < e; i++)
    {
        int num = isRow ? v[row][i] : v[i][row];

        if (abs(num - prev) > 1) return false; // 높이 차이가 2 이상이면 불가능

        if (num > prev) // 오르막 경사로 설치 필요
        {
            if (cnt < l) return false; // 충분한 공간이 없음

            for (int j = i - l; j < i; j++)
            {
                if (placed[j]) return false; // 이미 경사로가 설치된 곳이면 불가능
                placed[j] = true;
            }
            cnt = 1; // 새로운 숫자가 시작되므로 초기화
        }
        else if (num < prev) // 내리막 경사로 설치 필요
        {
            if (i + l - 1 >= e) return false; // 범위를 벗어나면 불가능

            for (int j = i; j < i + l; j++)
            {
                if (isRow && v[row][j] != num) return false; // 같은 높이인지 확인
                if (!isRow && v[j][row] != num) return false;
                if (placed[j]) return false; // 이미 경사로 설치된 곳이면 불가능
                placed[j] = true;
            }
            i += l - 1; // 경사로를 설치한 끝까지 이동
            cnt = 0; // 경사로 설치 완료
        }
        else cnt++; // 같은 숫자가 반복되면 cnt 증가

        prev = num;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;
    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += checkRow(v, 0, n, i, true);
        result += checkRow(v, 0, n, i, false);
    }

    cout << result;
}
