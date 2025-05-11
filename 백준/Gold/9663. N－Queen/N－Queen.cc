#include <iostream>
#include <vector>
using namespace std;

int N, boards = 0;
vector<bool> colUsed, leftDiagUsed, rightDiagUsed;

void Backtrack(int row)
{
    if (row == N)
    {
        boards++;
        return;
    }

    for (int col = 0; col < N; ++col)
    {
        // 좌측 대각선의 인덱스는 (row + col)
        // 우측 대각선의 인덱스는 (row - col + N - 1)
        if (!colUsed[col] && !leftDiagUsed[row + col] && !rightDiagUsed[row - col + N - 1])
        {
            colUsed[col] = true;
            leftDiagUsed[row + col] = true;
            rightDiagUsed[row - col + N - 1] = true;

            Backtrack(row + 1);

            // 백트래킹
            colUsed[col] = false;
            leftDiagUsed[row + col] = false;
            rightDiagUsed[row - col + N - 1] = false;
        }
    }
}

int main()
{
    cin >> N;
    colUsed.resize(N, false);
    leftDiagUsed.resize(2 * N - 1, false);
    rightDiagUsed.resize(2 * N - 1, false);

    Backtrack(0);
    cout << boards;
    return 0;
}
