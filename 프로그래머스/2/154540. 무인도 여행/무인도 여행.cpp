#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size()));
    int offset[4][2] {{0,1}, {0,-1}, {1,0}, {-1,0}};
    for(int i = 0; i < maps.size(); i++){
        for(int j =0 ; j < maps[i].size(); j++){
            if(visited[i][j] == true || maps[i][j] == 'X')continue;
            stack<pair<int, int>> dfs;
            dfs.push({i, j});
            visited[i][j] = true;
            int count = maps[i][j] - '0';
            while(!dfs.empty()){
                int x = dfs.top().second;
                int y = dfs.top().first;
                dfs.pop();
                for(int k = 0; k < 4; k++){
                    int xx = x + offset[k][0];
                    int yy = y + offset[k][1];
                    if(xx < maps[0].size() && xx >= 0 && yy < maps.size() && yy >= 0){
                        if(!visited[yy][xx] && maps[yy][xx] != 'X'){
                            dfs.push({yy, xx});
                            visited[yy][xx] = true;
                            count += maps[yy][xx] - '0';
                        }
                    }
                }
            }
            answer.push_back(count);
        }
    }
    if(answer.empty())return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}