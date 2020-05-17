/*************************************************************************
    > File Name: LeetCode-378.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 03:36:41 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int check(vector<vector<int>>& matrix, int x, int n, int m) {
        int cnt = 0, j = matrix.size();
        for (int i = 0; i < m; i++) {
            while(j && matrix[j - 1][i] > x) --j;
            cnt += j;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[n - 1][m - 1];
        int mid, ret;
        while (l < r) {
            mid = (l + r) >> 1;
            ret = check(matrix, mid, n, m);
            if (ret < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
