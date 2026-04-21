#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
	int answer = 0, n = board.size(), m = board[0].size();
    vector<vector<int>> diff(n + 1, vector<int>(m + 1));
	for (auto& row : skill)
	{
		int type = row[0], r1 = row[1], c1 = row[2], r2 = row[3], c2 = row[4], degree = row[5];
        degree = type == 1 ? -degree : degree;
		diff[r1][c1] += degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
	}
    
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            diff[i][j] += diff[i][j - 1];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            diff[j][i] += diff[j - 1][i];   
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] + diff[i][j] > 0) answer++;
        }
    }
    
	return answer;
}