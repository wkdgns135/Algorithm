#include <string>
#include <vector>

using namespace std;

int M, N;

vector<pair<int, int>> check_board(const vector<string>& board)
{
    vector<pair<int, int>> result;
    for (int i = 0; i < M - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (board[i][j] == ' ') continue;
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 1][j])
            {
                result.push_back({ i, j });
            }
        }
    }
    return result;
}

void erase_board(const vector<pair<int, int>>& targets, vector<string>& board)
{
    for (const auto& target : targets)
    {
        const auto& [y, x] = target;
        board[y][x] = ' ', board[y][x + 1] = ' ', board[y + 1][x + 1] = ' ', board[y + 1][x] = ' ';
    }
}

void move_board(vector<string>& board)
{
    for (int i = M - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == ' ')
            {
                int y = i - 1;
                while (y >= 0 && board[y][j] == ' ') y--;
                if(y >= 0){
                    board[i][j] = board[y][j];
                    board[y][j] = ' ';
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    M = m, N = n;

    vector<pair<int, int>> targets = check_board(board);
    while (!targets.empty())
    {
        erase_board(targets, board);
        move_board(board);
        targets = check_board(board);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == ' ') answer++;
        }
    }

    return answer;
}