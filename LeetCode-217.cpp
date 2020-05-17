/*************************************************************************
    > File Name: LeetCode-217.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 12:05:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
