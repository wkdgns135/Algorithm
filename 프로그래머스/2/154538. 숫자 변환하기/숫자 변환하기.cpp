#include <queue>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> v(y + 1, y);
    
    queue<int> bfs;
    bfs.push(x);
    v[x] = 0;
    
    while(!bfs.empty()){
        int num = bfs.front();
        bfs.pop();
        
        if(num == y){
            return v[num];
        }
        
        if(num + n <= y && v[num + n] > v[num] + 1){
            bfs.push(num + n);
            v[num + n] = v[num] + 1;
        }
        
        if(num * 2 <= y && v[num * 2] > v[num] + 1){
            bfs.push(num * 2);
            v[num * 2] = v[num] + 1;
        }
        
        if(num * 3 <= y && v[num * 3] > v[num] + 1){
            bfs.push(num * 3);
            v[num * 3] = v[num] + 1;
        }
    }
    
    return -1;
}