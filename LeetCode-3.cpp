/*************************************************************************
    > File Name: LeetCode-3.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 08:35:16 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    bool check(string &s, int l) {
        int cnt = 0;
        int arr[256] = {0};
        for (int i = 0; s[i]; i++) {
            arr[s[i]] += 1;
            if (arr[s[i]] == 1) cnt += 1;
            if (i >= l) {
                arr[s[i - l]] -= 1;
                if (arr[s[i - l]] == 0) cnt -= 1;
            }
            if (cnt == l) return 1;
        }
        return 0;
    }

    int bs(string &s, int l, int r) {
        if (l == r) return l;
        int mid = (l + r + 1) >> 1;
        if (check(s, mid)) return bs(s, mid, r);
        else return bs(s, l, mid - 1);
    }
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        return bs(s, 1, s.size());
    }
};
