#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void NormalizePiece(vector<pair<int, int>>& piece)
{
	int minY = 50, minX = 50;

	for (pair<int, int> i : piece)
	{
		auto [y, x] = i;
		if (minY > y) minY = y;
		if (minX > x) minX = x;
	}

	for (pair<int, int>& i : piece)
	{
		auto& [y, x] = i;
		y -= minY;
		x -= minX;
	}

	sort(piece.begin(), piece.end());
}

void RotatePiece(vector<pair<int, int>>& piece){
    for (auto& i : piece)
    {
        auto& [y, x] = i;
        swap(y, x);
        x = -x;
    }
}

vector<vector<pair<int, int>>> FindPieces(vector<vector<int>>& map, bool flag)
{
	vector < vector<pair<int, int>>> pieces;

	constexpr int offset[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	const int n = map.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == flag) continue;

			queue<pair<int, int>> bfs;
			bfs.push({ i, j });
			map[i][j] = flag;
			vector<pair<int, int>> piece = { {i, j} };

			while (!bfs.empty())
			{
				auto [y, x] = bfs.front();
				bfs.pop();

				for (int k = 0; k < 4; k++)
				{
					int yy = y + offset[k][0];
					int xx = x + offset[k][1];

					if (yy >= 0 && yy < n && xx >= 0 && xx < n && map[yy][xx] == !flag)
					{
						piece.push_back({ yy, xx });
						map[yy][xx] = flag;
						bfs.push({ yy, xx });
					}
				}
			}
			pieces.push_back(piece);
		}
	}

	return pieces;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = 0;

	vector<vector<pair<int, int>>> boardPieces = FindPieces(game_board, true);
	vector<bool> boardUsed(boardPieces.size());
	vector<vector<pair<int, int>>> tablePieces = FindPieces(table, false);

	for (auto& boardPiece : boardPieces) NormalizePiece(boardPiece);

	for (auto& tablePiece : tablePieces)
	{
		for (int i = 0; i < boardPieces.size(); i++)
		{
			if (tablePiece.size() != boardPieces[i].size() || boardUsed[i]) continue;

            vector<pair<int, int>> tmp = tablePiece;
            for(int j = 0; j < 4; j++){
                NormalizePiece(tmp);
                if (tmp == boardPieces[i])
                {
                    answer += tmp.size();
                    boardUsed[i] = true;
                    break;
                }
                RotatePiece(tmp);
            }
            if(boardUsed[i]) break;
		}
	}
	return answer;
}