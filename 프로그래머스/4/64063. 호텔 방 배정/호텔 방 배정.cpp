#include <bits/stdc++.h>
using namespace std;

long long findRoot(unordered_map<long long, long long> &parent, long long x)
{
    if (parent[x] == 0)return x;
    else
    {
        parent[x] = findRoot(parent, parent[x]);
        return parent[x];
    }
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    unordered_map<long long, long long> parent; // 부모 노드를 저장하는 맵

    for (long long room : room_number)
    {
        if (parent[room] == 0)
        {
            // 방이 비어있는 경우
            answer.push_back(room);
            parent[room] = findRoot(parent, room + 1); // 다음 방을 현재 방과 연결
        }
        else
        {
            // 방이 이미 차있는 경우, 다음 비어있는 방을 찾아 연결
            long long nextRoom = findRoot(parent, room);
            answer.push_back(nextRoom);
            parent[nextRoom] = findRoot(parent, nextRoom + 1); // 다음 방을 현재 방과 연결
        }
    }

    return answer;
}