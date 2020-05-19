/*************************************************************************
    > File Name: LeetCode-58.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Tue 19 May 2020 08:53:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s == "") return 0;
        int p1 = s.size() - 1, p2;
        while (p1 >= 0 && s[p1] == ' ') --p1;
        p2 = p1;
        while (p2 >= 0 && s[p2] != ' ') --p2;
        return p1 - p2;
    }
};
