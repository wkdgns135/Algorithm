#include <bits/stdc++.h>
using namespace std;

struct Road {
    long long x1, y1, x2, y2;
    int limit;

    bool vertical() const {
        return x1 == x2;
    }

    bool horizontal() const {
        return y1 == y2;
    }
};

struct Point {
    long long x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    size_t operator()(const Point& p) const {
        size_t h1 = hash<long long>{}(p.x);
        size_t h2 = hash<long long>{}(p.y);
        return h1 ^ (h2 << 1);
    }
};

const int INF = 1'000'000'001;

bool inRange(long long a, long long l, long long r) {
    return l <= a && a <= r;
}

bool onRoad(const Road& r, const Point& p) {
    if (r.vertical()) {
        return p.x == r.x1 && inRange(p.y, r.y1, r.y2);
    } else {
        return p.y == r.y1 && inRange(p.x, r.x1, r.x2);
    }
}

// 서로 다른 두 도로가 만나는 점을 구한다.
// 문제 조건상 서로 다른 두 도로는 최대 한 점에서만 만난다.
bool getIntersection(const Road& a, const Road& b, Point& out) {
    // 세로 - 가로
    if (a.vertical() && b.horizontal()) {
        long long x = a.x1;
        long long y = b.y1;

        if (inRange(x, b.x1, b.x2) && inRange(y, a.y1, a.y2)) {
            out = {x, y};
            return true;
        }
        return false;
    }

    // 가로 - 세로
    if (a.horizontal() && b.vertical()) {
        long long x = b.x1;
        long long y = a.y1;

        if (inRange(x, a.x1, a.x2) && inRange(y, b.y1, b.y2)) {
            out = {x, y};
            return true;
        }
        return false;
    }

    // 세로 - 세로: 같은 x에서 끝점으로만 만나는 경우
    if (a.vertical() && b.vertical()) {
        if (a.x1 != b.x1) return false;

        long long lo = max(a.y1, b.y1);
        long long hi = min(a.y2, b.y2);

        if (lo == hi) {
            out = {a.x1, lo};
            return true;
        }
        return false;
    }

    // 가로 - 가로: 같은 y에서 끝점으로만 만나는 경우
    if (a.horizontal() && b.horizontal()) {
        if (a.y1 != b.y1) return false;

        long long lo = max(a.x1, b.x1);
        long long hi = min(a.x2, b.x2);

        if (lo == hi) {
            out = {lo, a.y1};
            return true;
        }
        return false;
    }

    return false;
}

vector<int> solution(vector<vector<int>> city, vector<vector<int>> road) {
    int n = city.size();
    int m = road.size();

    vector<Road> roads;
    roads.reserve(m);

    for (auto& r : road) {
        roads.push_back({
            r[0], r[1], r[2], r[3], r[4]
        });
    }

    unordered_map<Point, int, PointHash> id;
    vector<Point> points;
    vector<int> cameraLimit;

    auto getId = [&](Point p) -> int {
        auto it = id.find(p);
        if (it != id.end()) return it->second;

        int idx = points.size();
        id[p] = idx;
        points.push_back(p);
        cameraLimit.push_back(INF);
        return idx;
    };

    vector<vector<int>> roadPoints(m);

    auto addPointToRoad = [&](int roadIdx, Point p) {
        int pid = getId(p);
        roadPoints[roadIdx].push_back(pid);
    };

    // 1. 각 도로의 양 끝점, 카메라 위치 추가
    for (int i = 0; i < m; i++) {
        const Road& r = roads[i];

        Point start = {r.x1, r.y1};
        Point end = {r.x2, r.y2};

        Point cam;
        if (r.vertical()) {
            cam = {r.x1, (r.y1 + r.y2) / 2};
        } else {
            cam = {(r.x1 + r.x2) / 2, r.y1};
        }

        addPointToRoad(i, start);
        addPointToRoad(i, end);
        addPointToRoad(i, cam);

        int camId = getId(cam);
        cameraLimit[camId] = min(cameraLimit[camId], r.limit);
    }

    // 2. 도시 위치 추가
    vector<int> cityId(n);

    for (int i = 0; i < n; i++) {
        Point p = {city[i][0], city[i][1]};
        cityId[i] = getId(p);

        for (int j = 0; j < m; j++) {
            if (onRoad(roads[j], p)) {
                roadPoints[j].push_back(cityId[i]);
            }
        }
    }

    // 3. 도로끼리 만나는 교차점 추가
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            Point cross;
            if (getIntersection(roads[i], roads[j], cross)) {
                int cid = getId(cross);
                roadPoints[i].push_back(cid);
                roadPoints[j].push_back(cid);
            }
        }
    }

    // 4. 각 도로 위의 점들을 정렬한 뒤, 인접한 점끼리 간선 연결
    int V = points.size();
    vector<vector<int>> graph(V);

    for (int i = 0; i < m; i++) {
        auto& vec = roadPoints[i];

        sort(vec.begin(), vec.end(), [&](int a, int b) {
            if (roads[i].vertical()) {
                return points[a].y < points[b].y;
            } else {
                return points[a].x < points[b].x;
            }
        });

        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        for (int j = 0; j + 1 < (int)vec.size(); j++) {
            int a = vec[j];
            int b = vec[j + 1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    // 5. 최대 bottleneck 경로 탐색
    // dist[v] = 1번 도시에서 v까지 갈 때 가능한 최고 속도
    // 즉, 지나온 카메라 제한속도의 최솟값 중 최대값
    vector<int> dist(V, -1);
    priority_queue<pair<int, int>> pq;

    int start = cityId[0];
    dist[start] = INF;
    pq.push({INF, start});

    while (!pq.empty()) {
        auto [speed, cur] = pq.top();
        pq.pop();

        if (dist[cur] != speed) continue;

        for (int nxt : graph[cur]) {
            int nextSpeed = min(speed, cameraLimit[nxt]);

            if (dist[nxt] < nextSpeed) {
                dist[nxt] = nextSpeed;
                pq.push({nextSpeed, nxt});
            }
        }
    }

    vector<int> answer;

    for (int i = 1; i < n; i++) {
        int result = dist[cityId[i]];

        // 카메라를 하나도 지나지 않고 도착 가능하면 INF 상태 그대로 도착한다.
        if (result == INF) answer.push_back(0);
        else answer.push_back(result);
    }

    return answer;
}