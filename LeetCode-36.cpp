/*************************************************************************
    > File Name: LeetCode-36.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Tue 19 May 2020 08:50:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int x[9], y[9], z[9];
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (x[i] & (1 << num)) return false;
                if (y[j] & (1 << num)) return false;
                if (z[i / 3 * 3 + j / 3] & (1 << num)) return false;
                x[i] |= (1 << num);
                y[j] |= (1 << num);
                z[i / 3 * 3 + j / 3] |= (1 << num);
            }
        }
        return true;
    }
};
