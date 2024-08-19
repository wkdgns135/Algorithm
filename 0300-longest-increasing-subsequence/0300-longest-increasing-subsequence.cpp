#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i = 0 ; i < nums.size(); i++){
           const int index = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
           if(v.size() == index)v.push_back(nums[i]);
           else v[index] = nums[i];
        }
        return v.size();
    }
};
