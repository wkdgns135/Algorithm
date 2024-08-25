#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    visited[0][0] = 1;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    
    while(!bfs.empty()){
        int y = bfs.front().first;
        int x = bfs.front().second;
        bfs.pop();
        for(int i = 0 ; i < 4; i++){
            int col = dy[i] + y;
            int row = dx[i] + x;
            if(col == -1 || row == -1 || col == n || row == m)continue;
            if(maps[col][row] == 0)continue;
            if(visited[col][row] > 0)continue;
            visited[col][row] = visited[y][x] + 1;
            bfs.push({col, row});
        }
    }
    
    return visited[n-1][m-1];
}