/*************************************************************************
    > File Name: LeetCode-3.2.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 08:40:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ind[256] = {0};
        int l = 0, ans = 0;//以当前字符为结尾向前找对应最长串
        for (int i = 0; s[i]; i++) {
            l += 1;
            l = min(l, (i + 1) - ind[s[i]]);
            ind[s[i]] = i + 1;
            ans = max(ans, l);
        }
        return ans;
    }
};
