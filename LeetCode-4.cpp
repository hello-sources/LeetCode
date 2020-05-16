/*************************************************************************
    > File Name: LeetCode-4.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 09:19:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    double bs(vector<int> &n1, vector<int> &n2, int i, int j, int k) {
        if (i == n1.size()) return n2[k - 1];
        if (j == n2.size()) return n1[k - 1];
        if (k == 1) return min(n1[i], n2[j]);
        int a, b;
        a = k / 2 > n1.size() - i ? n1.size() - i : k / 2;
        b = k - a > n2.size() - j ? n2.size() - j : k - a;
        a = k - b;
        if (n1[i + a - 1] < n2[j + b - 1]) {
            return bs(n1, n2, i + a, j, k - a);
        }
        return bs(n1, n2, i, j + b, k - b);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int  n = nums1.size(), m = nums2.size();
        double val1 = bs(nums1, nums2, 0, 0, (n + m + 1) / 2);
        if ((n + m) % 2 == 0) {
            double val2 = bs(nums1, nums2, 0, 0, (n + m) / 2 + 1);
            return (val2 + val1) / 2;
        }
        return val1;
    }
};
