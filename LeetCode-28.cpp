/*************************************************************************
    > File Name: LeetCode-28.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Tue 19 May 2020 08:42:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind[256];
        for (int i = 0; i < 256; i++) ind[i] = needle.size() + 1;
        for (int i = 0; needle[i]; i++) {
            ind[needle[i]] = needle.size() - i;
        }
        for (int i = 0, I = haystack.size() - needle.size(); i <= I; ) {
            int j = 0;
            for (; needle[j]; j++) {
                if (haystack[i + j] == needle[j]) continue;
                i += ind[haystack[i + needle.size()]];
                break;
            }
            if (needle[j] == 0) return i;
        }
        return -1;
    }
};
