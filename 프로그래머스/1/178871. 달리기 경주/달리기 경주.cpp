#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> m;
    for(int i = 0; i < players.size(); i++)m.insert({players[i], i});
    for(auto calling : callings){
        int index = m[calling];
        m[players[index-1]]++;
        m[players[index]]--;
        players[index] = players[index-1];
        players[index-1] = calling;
    }
    return players;
}