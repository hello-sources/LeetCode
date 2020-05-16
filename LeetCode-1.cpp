/*************************************************************************
    > File Name: LeetCode-1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 07:44:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    unordered_map<int, int> h;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) == h.end()) {
                h[nums[i]] = i;
                continue;
            }
            ret.push_back(h[target - nums[i]]);
            ret.push_back(i);
            break;
        }
        return ret;
    }
};
