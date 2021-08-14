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
        unordered_map<int,int> row,col;
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
                //if this row has a 0
                if(row[i]==1){
                    //make all the elements of this row 0
                    for(int k=0;k<c;k++)
                        matrix[i][k]=0;
                }
                //if this column also has a 0
                if(col[j]==1){
                    //make all the elements of this column 0
                    for(int k=0;k<r;k++)
                        matrix[k][j]=0;
                }
           }
        }
    }
};


