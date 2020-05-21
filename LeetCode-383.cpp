/*************************************************************************
    > File Name: LeetCode-383.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Thu 21 May 2020 07:31:48 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    bool canConstruct(string r, string m) {
        int code[256] = {0};
        for (int i = 0; m[i]; i++) code[m[i]] += 1;
        for (int i = 0; r[i]; i++) {
            if (code[r[i]] == 0) return false;
            code[r[i]]--;
        }
        return true;
    }
};
