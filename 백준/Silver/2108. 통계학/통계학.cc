#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;  cin >> n;
    int sum = 0, maxVal = -4000, minVal = 4000, maxRate = 0;
    vector<int> v;
    unordered_map<int, int> map;
    vector<int> vv;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (maxVal < num)maxVal = num;
        if (minVal > num)minVal = num;
        sum += num;
        v.push_back(num);
        map[num]++;
        if (maxRate < map[num])maxRate = map[num];
    }

    for (auto& i : map) if (i.second == maxRate)vv.push_back(i.first);

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    cout << floor(((float)sum / n) + 0.5f) << '\n'; // 산술 평균
    cout << v[n / 2] << '\n'; // 중앙 값
    if (vv.size() > 1)cout << vv[1] << '\n';
    else cout << vv[0] << '\n';
    cout << maxVal - minVal << '\n'; // 범위
}
