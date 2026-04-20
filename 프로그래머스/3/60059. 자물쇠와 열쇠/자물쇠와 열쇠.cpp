#include <vector>

using namespace std;

void rotate(vector<pair<int,int>> &v){
    for(auto &[y, x] : v){
        int ny = -x;
        int nx = y;
        y = ny;
        x = nx;
    }
    
    int minY = 20, minX = 20;
    for(auto &[y, x] : v){
        minY = min(minY, y);
        minX = min(minX, x);
    }
    
    for(auto &[y, x] : v){
        y -= minY;
        x -= minX;
    }
}

bool check(int n, int count, vector<pair<int,int>> &v, vector<vector<int>> &lock){
    int size = lock.size();
    for(int i = -n; i < size + n; i++){
        for(int j = -n; j < size + n; j++){
            int result = 0; 
            for(auto &[y, x] : v){
                int yy = y + i;
                int xx = x + j;
                
                if(yy < 0 || yy >= size || xx < 0 || xx >= size) continue;
                if(lock[yy][xx]) {
                    result = 0;
                    break;
                }
                result++;
            }
            if(result == count) return true;
        }
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<pair<int,int>> v;
    
    for(int i = 0; i < key.size(); i++){
        for(int j = 0; j < key.size(); j++){
            if(key[i][j]) v.push_back({i, j});
        }
    }
    
    int count = 0;
    for(int i = 0; i < lock.size(); i++){
        for(int j = 0; j < lock.size(); j++){
            if(!lock[i][j]) count++;
        }
    }
    
    for(int i = 0; i < 4; i++){
        rotate(v);
        if(check(key.size(), count, v, lock)) return true;
    }
    
    return false;
}