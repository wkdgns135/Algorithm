#include <bits/stdc++.h>
using namespace std;

// Union-Find 자료구조를 위한 parent와 depth 배열
vector<int> parent, depth;

// Find 연산 (경로 압축 적용)
int Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

// Union 연산
bool Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX == rootY) return false; // 이미 같은 집합에 속해 있음 (사이클 발생)
    if (depth[rootX] > depth[rootY]) {
        parent[rootY] = rootX;
    }
    else if (depth[rootX] < depth[rootY]) {
        parent[rootX] = rootY;
    }
    else {
        parent[rootY] = rootX;
        depth[rootX]++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    parent.resize(n);
    depth.resize(n, 0);

    // 초기화
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        // 사이클이 발생하면 i번째 차례 출력
        if (!Union(a, b)) {
            cout << i << '\n';
            return 0;
        }
    }

    // 모든 차례를 처리한 후에도 사이클이 없으면 0 출력
    cout << 0 << '\n';
    return 0;
}
