/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minimumPathSum.cpp
 * @created     : Thursday Aug 05, 2021 19:09:55 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();

        //populating the first row
        for(int j=1;j<c;j++)
            grid[0][j]+=grid[0][j-1];


        //populating the first column
        for(int i=1;i<r;i++)
            grid[i][0]+=grid[i-1][0];

        //now the whole matrix
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }

        return grid[r-1][c-1];
    }
};
