/*************************************************************************
    > File Name: LeetCode-374.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 12:44:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int guessNumber(int n) {
        long head = 1, tail = n, mid;
        while (head <= tail) {
            mid = (head + tail) >> 1;
            int ret = guess(mid);
            if (ret == 0) return mid;
            if (ret < 0) tail = mid - 1;
            else head = mid + 1;
        }
        return -1;
    }
};
