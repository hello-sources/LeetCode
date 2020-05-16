/*************************************************************************
    > File Name: LeetCode-1.1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 07:54:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:

    typedef pair<int, int> PII;
    unordered_map<int, int> h;
    int bs(vector<PII>& nums, int l, int r, int x) {
        int mid = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[mid].first == x) return mid;
            if (nums[mid].first > x) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<PII> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(PII(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int ind = bs(arr, i + 1, arr.size() - 1, target - arr[i].first);
            if (ind == -1) continue;
            int ind1 = arr[i].second, ind2 = arr[ind].second;
            if (ind1 > ind2) swap(ind1, ind2);
            ret.push_back(ind1);
            ret.push_back(ind2);
        }
        return ret;
    }
};
