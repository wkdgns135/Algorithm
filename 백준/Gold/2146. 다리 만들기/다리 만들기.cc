#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    int offset[4][2] = { {0,1},{ 0,-1 },{1,0},{-1,0} };

    // 입력 받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    // 섬 구분 및 가장자리 탐색
    vector<vector<pair<int, int>>> edges;
    int index = 2; // 섬 번호는 2부터 시작
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != 1) continue; // 섬이 아닌 경우 스킵
            queue<pair<int, int>> bfs;
            bfs.push({ i, j });
            v[i][j] = index;
            vector<pair<int, int>> tmp;
            while (!bfs.empty())
            {
                auto& [y, x] = bfs.front();
                bfs.pop();
                bool isEdge = false;
                for (int k = 0; k < 4; k++)
                {
                    int xx = offset[k][0] + x;
                    int yy = offset[k][1] + y;
                    if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                    if (v[yy][xx] != 1)
                    {
                        if (v[yy][xx] == 0) isEdge = true; // 가장자리 확인
                        continue;
                    }
                    v[yy][xx] = index;
                    bfs.push({ yy, xx });
                }
                if (isEdge) tmp.push_back({ y, x });
            }
            edges.push_back(tmp);
            index++;
        }
    }

    // 최단 거리 계산
    int result = INT_MAX;
    for (int i = 0; i < edges.size(); i++)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // 거리 배열 초기화
        queue<pair<int, int>> bfs;

        // 현재 섬의 가장자리에서 BFS 시작
        for (const auto& point : edges[i])
        {
            bfs.push(point);
            dist[point.first][point.second] = 0;
        }

        while (!bfs.empty())
        {
            auto [y, x] = bfs.front();
            bfs.pop();

            for (int k = 0; k < 4; k++)
            {
                int xx = offset[k][0] + x;
                int yy = offset[k][1] + y;
                if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                if (v[yy][xx] == i + 2) continue;
                if (dist[y][x] + 1 < dist[yy][xx])
                {
                    dist[yy][xx] = dist[y][x] + 1;
                    if (v[yy][xx] > 1 && v[yy][xx] != i + 2) // 다른 섬에 도달
                    {
                        result = min(result, dist[yy][xx]);
                        break;
                    }
                    bfs.push({ yy, xx });
                }
            }
        }
    }

    cout << result - 1 << '\n'; // 최단 거리 출력
}
