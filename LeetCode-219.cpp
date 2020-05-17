/*************************************************************************
    > File Name: LeetCode-219.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 12:12:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k += 1;
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); i++) {
            s[nums[i]] += 1;
            if (i >= k) s[nums[i - k]] -= 1;
            if (s[nums[i]] == 2) return true;
        }
        return false;
    }
};
