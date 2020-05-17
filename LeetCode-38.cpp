/*************************************************************************
    > File Name: LeetCode-38.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 17 May 2020 11:50:40 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ret = "", str = countAndSay(n - 1);
        char tmp[10];
        int cnt = 1;
        for (int i = 1, j = 0; str[i]; i++) {
            if (str[i] == str[j]) cnt += 1;
            else {
                sprintf(tmp, "%d%c", cnt, str[j]);
                ret += tmp;
                cnt = 1, j = i;
            }
        }
        sprintf(tmp, "%d%c", cnt, str[str.size() - 1]);
        ret += tmp;
        return ret;
    }
};
