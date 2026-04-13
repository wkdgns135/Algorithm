#include <vector>
#include <queue>
#include <climits>
#include <tuple>
#include <algorithm>

using namespace std;

bool isValid(int n, int x){
    return x < n && x >= 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    vector<vector<vector<int>>> mdt(n, vector<vector<int>>(n, vector<int>(4, INT_MAX)));
    queue<tuple<int,int,int>> bfs;
    fill(mdt[0][0].begin(), mdt[0][0].end(), 0);
    bfs.push({0,0,0});
    bfs.push({0,0,1});
    
    static constexpr int offset[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    while(!bfs.empty()){
        auto [x, y, d] = bfs.front();
        bfs.pop();
        
        for(int i = 0; i < 4; i++){
            int xx = x + offset[i][1];
            int yy = y + offset[i][0];
            int cost = d == i ? 100 : 600;
            if(isValid(n, xx) && isValid(n, yy) && !board[yy][xx] && mdt[yy][xx][i] > mdt[y][x][d] + cost){
                mdt[yy][xx][i] = mdt[y][x][d] + cost;
                bfs.push({xx, yy, i});
            }
        }
    }
    
    return *min_element(mdt[n - 1][n - 1].begin(), mdt[n - 1][n - 1].end());
}