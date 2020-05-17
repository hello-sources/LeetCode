/*************************************************************************
    > File Name: LeetCode-278.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 12:22:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        long long head = 1, tail = n, mid;
        while (head < tail)  {
            mid = (head + tail) >> 1;
            if (isBadVersion(mid)) tail = mid;
            else head = mid + 1;
        }
        return head;
    }
};
