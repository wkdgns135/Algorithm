#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> v(n, vector<pair<int,int>>());
    vector<pair<int, bool>> mdt(n, {INT_MAX, false});
    for (int i = 0; i < m; i++) {
        int from, dst, cost; cin >> from >> dst >> cost;
        v[from - 1].push_back({ dst - 1, cost });
    }

    int start, end; cin >> start >> end;
    --start, --end;

    int index = start;
    mdt[index] = {0, true};

    while (true) {
        for (int i = 0; i < v[index].size(); i++) {
            mdt[v[index][i].first].first = min(v[index][i].second + mdt[index].first, mdt[v[index][i].first].first);
        }

        pair<int, int> next = { INT_MAX, -1};
        for (int i = 0; i < mdt.size(); i++) {
            if (mdt[i].second)continue;
            if (next.first > mdt[i].first) {
                next.first = mdt[i].first;
                next.second = i;
            }
        }

        if (next.second == -1)break;
        mdt[next.second].second = true;
        index = next.second;
    }

    cout << mdt[end].first;
}
