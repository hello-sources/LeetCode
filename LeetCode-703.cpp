/*************************************************************************
    > File Name: LeetCode-703.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 06:28:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class KthLargest {
public:
    typedef pair<int, int> PII;
    set<PII> s;
    int k, t;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
        return ;
    }
    
    int add(int val) {
        if (s.size() < k) {
            s.insert(PII(val, t++));
        } else if (val > s.begin()->first) {
            s.erase(s.begin());
            s.insert(PII(val, t++));
        }
        return s.begin()->first;
    }
};
