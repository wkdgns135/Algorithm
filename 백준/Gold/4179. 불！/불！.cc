#include <bits/stdc++.h>
using namespace std;

int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int r, c;

bool IsValidIndex(int x, int y)
{
    return x < c && x >= 0 && y < r && y >= 0;
}

void FireSpread(vector<vector<int>>& grid, set<pair<int, int>> &fires)
{
    set<pair<int, int>> nextFire;
    for (const auto& [y, x] : fires)
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            if (IsValidIndex(xx, yy) && grid[yy][xx] == 1)
                nextFire.insert({ yy, xx });
        }
    }
    for (const auto& [y, x] : nextFire) grid[y][x] = 2;
    swap(fires, nextFire);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    vector<vector<bool>> visited(r, vector<bool>(c));
    set<pair<int, int>> fires;
    pair<int, int> start;
    for (int i = 0; i < r; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < c; j++)
        {
            if (str[j] == '#')grid[i][j] = 0;
            else if (str[j] == 'F')
            {
                fires.insert({ i,j });
                grid[i][j] = 2;
            }
            else grid[i][j] = 1;

            if (str[j] == 'J')start = { i, j };
        }
    }

    queue<tuple<int,int,int>> bfs; // {time, x, y}
    visited[start.first][start.second] = true;
    bfs.push({ 1, start.second, start.first });
    int time = 0;

    while (!bfs.empty())
    {
        auto [currentTime, x, y] = bfs.front();
        bfs.pop();

        if (currentTime != time)
        {
            FireSpread(grid, fires);
            time++;
        }

        for (int i = 0; i < 4; i++)
        {
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            if (!IsValidIndex(xx, yy))
            {
                cout << time;
                return 0;
            }

            if (grid[yy][xx] == 1 && !visited[yy][xx])
            {
                visited[yy][xx] = true;
                bfs.push({ currentTime + 1, xx, yy });
            }
        }
    }
    cout << "IMPOSSIBLE";
}
