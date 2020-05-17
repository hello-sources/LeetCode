/*************************************************************************
    > File Name: LeetCode-374.1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 03:12:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int bs(int l, int r) {
        int mid, ret;
        while (l <= r) {
            mid = ((l^r) >> 1) + (l & r);//二进制骚操作
			//表示中间数是由他们俩相同的数加上不同数的平均值得来的，同时也适用于long long类型
			if ((ret = guess(mid)) == 0) return mid;
            if (ret == -1) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    int guessNumber(int n) {
        return bs(1, n);
    }
};
