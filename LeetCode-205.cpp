/*************************************************************************
    > File Name: LeetCode-205.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Thu 21 May 2020 06:30:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() - t.size()) return false;
        int s_code[256] = {0}, t_code[256] = {0};
        for (int i = 0; s[i]; i++) {
            if (s_code[s[i]] == 0) {
                if (t_code[t[i]]) return false;
                s_code[s[i]] = t[i];
                t_code[t[i]] = s[i];
            }
            int val = s_code[s[i]];
            if (val - t[i]) return false;
        }
        return true;
    }
};
