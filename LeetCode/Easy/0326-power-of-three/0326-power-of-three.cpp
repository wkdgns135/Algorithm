#include <bits/stdc++.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0)return false;
        vector<int> v(20);
        int i = 0;
        for(int i = 0; i < 20; i++)v[i] = pow(3, i);
        for(int i : v)if(i == n)return true;
        return false;
    }
};