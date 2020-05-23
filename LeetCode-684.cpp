/*************************************************************************
    > File Name: LeetCode-684.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 23 May 2020 02:18:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    struct UnionSet {
        int *fa;
        UnionSet(int n) {
            fa = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
            }
            return ;
        }
        int get(int x) {
            return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
        }
        int merge(int a, int b) {
            if (get(a) == get(b)) return 0;
            fa[get(a)] = get(b);
            return 1;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionSet u(edges.size());
        vector<int> ret;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (u.merge(a, b)) continue;
            ret.push_back(a);
            ret.push_back(b);
            break;
        }
        return ret;
    }
};
