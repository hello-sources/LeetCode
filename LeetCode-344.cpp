/*************************************************************************
    > File Name: LeetCode-344.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Thu 21 May 2020 07:12:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j;i++, j--) {
            swap(s[i], s[j]);
        }
        return ;
    }
};
