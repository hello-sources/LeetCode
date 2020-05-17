/*************************************************************************
    > File Name: LeetCode-88.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 12:00:29 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, p1 = m - 1, p2 = n - 1;
        while (p1 > 0 || p2 >= 0) {
            if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])) {
                nums1[k--] = nums1[p1--];
            } else {
                nums1[k--] = nums2[p2--];
            }
        }
    }
};
