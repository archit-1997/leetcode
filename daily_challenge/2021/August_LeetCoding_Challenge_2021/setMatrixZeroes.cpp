/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : setMatrixZeroes.cpp
 * @created     : Saturday Aug 14, 2021 07:14:58 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        bool col0=false;
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0)
                col0=true;
            for(int j=1;j<c;j++){
                //if this is a zero, mark the head of row and col as 0
                if(matrix[i][j]==0){
                    //head of the row
                    matrix[i][0]=0;
                    //head of the col
                    matrix[0][j]=0;
                }
            }
        }

        //just need to iterate
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0)
                matrix[i][0]=0;
        }
    }
};



