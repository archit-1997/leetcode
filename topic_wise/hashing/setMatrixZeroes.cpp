/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : setMatrixZeroes.cpp
 * @created     : Thursday Aug 05, 2021 20:03:02 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();

        //we need to maintain a map for row and column
        set<int> row,col;

        //traverse and mark the rows and columns which have 0 in them
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        //make all those rows zeroes which are in row
        for(auto it=row.begin();it!=row.end();it++){
            int rnum=*it;
            for(int j=0;j<c;j++)
                matrix[rnum][j]=0;
        }

        //make all those columns zeroes which are in col
        for(auto it=col.begin();it!=col.end();it++){
            int cnum=*it;
            for(int i=0;i<r;i++)
                matrix[i][cnum]=0;
        }

    }
};
