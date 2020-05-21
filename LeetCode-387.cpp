/*************************************************************************
    > File Name: LeetCode-387.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Thu 21 May 2020 07:37:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int code[256] = {0};
        for (int i = 0; s[i]; i++) code[s[i]] += 1;
        for (int i = 0; s[i]; i++) if (code[s[i]] == 1) return i;
        return -1;
    }
};
