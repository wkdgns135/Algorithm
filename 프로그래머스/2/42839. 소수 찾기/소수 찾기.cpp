#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10000000;
bool primeNums[SIZE];
int answer = 0;

void bt(string &numbers, vector<bool> &visited, string &s, int depth){
    if(!primeNums[stoi(s)]){
        cout << s << ' ';
        primeNums[stoi(s)] = true;
        answer++;
    }
    if(depth == -1)return;
    for(int i = 0; i < numbers.size(); i++){
        if(visited[i])continue;
        visited[i] = true;
        s[depth] = numbers[i];
        bt(numbers, visited, s, depth - 1);
        visited[i] = false;
        s[depth] = '0';
    }
}

int solution(string numbers) {
    int n = numbers.size();
    primeNums[0] = true, primeNums[1] = true;
    for(int i = 2; i <= sqrt(SIZE); i++){
        if(primeNums[i])continue;
        for(int j = i * 2; j < SIZE; j += i){
            primeNums[j] = true;
        }
    }
    vector<bool> visited(n);
    string s(n, '0');
    bt(numbers, visited, s, n - 1);
    return answer;
}