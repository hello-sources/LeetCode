/*************************************************************************
    > File Name: LeetCode-685.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 23 May 2020 03:18:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    struct UnionSet {
        int *fa, cnt;
        UnionSet(int n) {
            fa = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
            }
            cnt = n;
            return ;
        }
        int get(int x) {
            return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
        }
        int merge(int a, int b) {
            if (get(a) == get(b)) return 0;
            cnt -= 1;
            fa[get(a)] = get(b);
            return 1;
        }
    }; 
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int indeg[edges.size() + 1];
        int outdeg[edges.size() + 1];
        int fa[edges.size() + 1];
        int vis[edges.size() + 1];
        memset(indeg, 0, sizeof(indeg));
        memset(outdeg, 0, sizeof(outdeg));
        memset(fa, 0, sizeof(fa));
        memset(vis, 0, sizeof(vis));
        int flag = -1;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            indeg[v] += 1;
            outdeg[u] += 1;
            fa[v] = u; 
            if (indeg[v] == 2) flag = v;
        }
        if (flag != -1) {
            for (int i = edges.size() - 1; i >= 0; i--) {
                if (flag - edges[i][1]) continue;
                UnionSet u(edges.size());
                for (int j = 0; j < edges.size(); j++) {
                    if (i == j) continue;
                    u.merge(edges[j][0], edges[j][1]);
                }
                if (u.cnt != 1) continue;
                return edges[i];
            }
        }
        queue<int> q;
        for (int i = 1; i <= edges.size(); i++) {
            if (outdeg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int ind = q.front();
            vis[ind] = 1;
            q.pop();
            outdeg[fa[ind]] -= 1;
            if (outdeg[fa[ind]] == 0) q.push(fa[ind]);
        }
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (vis[u] || vis[v]) continue;
            return edges[i];
        }
        return edges[0]; // 没用的
    }
};
