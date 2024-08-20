#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> answer(intervals.size());
        unordered_map<int, int> map;
        for (int i = 0; i < intervals.size(); i++)map[intervals[i][0]] = i;

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int>b) {
            return a[0] < b[0];
            });

        for (int i = 0; i < intervals.size(); i++) {
            auto it = lower_bound(intervals.begin(), intervals.end(), intervals[i][1], [](const vector<int>& interval, int value) {
                    return value > interval[0];
            });
            if (it != intervals.end()) {
                int index = it - intervals.begin();
                int start = intervals[index][0];
                answer[map[intervals[i][0]]] = map[start];
            }
            else {
                answer[map[intervals[i][0]]] = -1;
            }
        }

        return answer;
    }
};