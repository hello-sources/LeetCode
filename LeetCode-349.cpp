/*************************************************************************
    > File Name: LeetCode-349.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 12:34:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> s;
        for (int i = 0; i < nums1.size(); i++) {
            s[nums1[i]] = 1;
        } 
        for (int i = 0; i < nums2.size(); i++) {
            if (s[nums2[i]] == 0) continue;
            ret.push_back(nums2[i]);
            s[nums2[i]] -= 1;
        }
        return ret;
    }
};
