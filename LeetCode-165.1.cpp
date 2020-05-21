/*************************************************************************
    > File Name: LeetCode-165.1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Thu 21 May 2020 06:22:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int getNext(string &str, int i, int &val) {
        val = 0;
        while (str[i] && str[i] <= '9' && str[i] >= '0') {
            val = val * 10 + str[i] - '0';
            i++;
            }
        if (str[i]) ++i;
        return i;
    }
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, val1, val2;
        while (version1[i] || version2[j]) {
            i = getNext(version1, i, val1);
            j = getNext(version2, j, val2);
            if (val1 - val2) return val1 > val2 ? 1 : -1;
        }
        return 0;
    }
};
