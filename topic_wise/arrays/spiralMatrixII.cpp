/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : spiralMatrixII.cpp
 * @created     : Thursday Aug 05, 2021 16:58:25 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count=1;
        int up=0,down=n-1,left=0,right=n-1;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int dir=0;
        while(up<=down && left<=right){
            if(dir==0){
                //we have to fill the top row
                for(int j=left;j<=right;j++)
                    matrix[up][j]=count++;
                up++;
                dir=1;
            }
            else if(dir==1){
                //we have to fill the rightmost column
                for(int i=up;i<=down;i++)
                    matrix[i][right]=count++;
                right--;
                dir=2;
            }
            else if(dir==2){
                //we have to fill the bottom row
                for(int j=right;j>=left;j--)
                    matrix[down][j]=count++;
                down--;
                dir=3;
            }
            else if(dir==3){
                //we have to fill the leftmost row
                for(int i=down;i>=up;i--)
                    matrix[i][left]=count++;
                left++;
                dir=0;
            }
        }
        return matrix;
    }
};
