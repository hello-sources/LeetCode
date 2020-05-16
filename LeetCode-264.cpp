/*************************************************************************
    > File Name: LeetCode-264.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 07:17:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    set<long long> s;
    int nthUglyNumber(long long n) {
        s.clear();
        s.insert(1);
        for (int i = 1; i < n; i++) {
            long long val = *s.begin();
            s.erase(s.begin());
            s.insert(val * 2);
            s.insert(val * 3);
            s.insert(val * 5);
        }
        return *s.begin();
    }
};
