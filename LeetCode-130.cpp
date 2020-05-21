/*************************************************************************
    > File Name: LeetCode-130.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Thu 21 May 2020 08:48:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    struct UnionSet {
        int *fa, *cnt;
        UnionSet(int n) {
            fa = new int[n + 1];
            cnt = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
                cnt[i] = 1;
            }
        }
        bool isroot(int x) {
            return x == fa[x];
        }
        int get(int x) {
            return (fa[x] = (x == fa[x] ? x : get(fa[x])));
        }
        void merge(int a, int b) { 
            int aa = get(a), bb = get(b);
            if (aa == bb) return ;
            fa[aa] = bb;
            cnt[bb] += cnt[aa];
            return ;
        }
        ~UnionSet() {
            delete[] fa;
            delete[] cnt;
        }
    };
    int n, m;
    int ind(int i, int j) {
        return (i * m) + j + 1;
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return ;
        n = board.size();
        m = board[0].size();
        UnionSet u(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') continue;
                if (i && board[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
                if (j && board[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
                if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
                if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') continue;
                if (u.get(ind(i, j)) == u.get(0)) continue;
                board[i][j] = 'X';
            }
        }
        return ;
    }
};
