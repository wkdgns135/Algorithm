#include <string>
#include <vector>
#include <climits>

using namespace std;

int distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    if(distance(x, y, r, c) % 2 != k % 2 || distance(x, y, r, c) > k) return "impossible";
    x--, y--, r--, c--;
    static constexpr int offset[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
    static constexpr char direction[4] = {'d','l','r','u'};
    string answer;
    answer.reserve(k);
    while(distance(x, y, r, c) < k){
        for(int i = 0; i < 4; i++){
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m){
                x = xx;
                y = yy;
                answer.push_back(direction[i]);
                k--;
                break;
            }
        }
    }

    while(k--){
        for(int i = 0; i < 4; i++){
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(distance(x, y, r, c) > distance(xx, yy, r, c)){
                    x = xx;
                    y = yy;
                    answer.push_back(direction[i]);
                    break;
                }
            }
        }
    }
    
    return answer;
}