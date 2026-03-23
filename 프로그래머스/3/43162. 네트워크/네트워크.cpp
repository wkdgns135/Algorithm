#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> parent;

int Find(int x){
    if(x == parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    int aa = Find(a);
    int bb = Find(b);
    
    if(aa >= bb){
        parent[a] = bb;
    }else{
        parent[b] = aa;
    }
}

int solution(int n, vector<vector<int>> computers) {
    parent.resize(n + 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j]){
                Union(i + 1, j + 1);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j]){
                Union(i + 1, j + 1);
            }
        }
    }
    
    unordered_set<int> s;
    for(int i = 1; i <= n; i++) s.insert(parent[i]);
    
    return s.size();
}