/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : spiralMatrix.cpp
 * @created     : Thursday Aug 05, 2021 15:15:53 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size(),col=matrix[0].size();

        int up=0,down=row-1,left=0,right=col-1;
        int dir=0;
        while(up<=down && left<=right){
            if(dir==0){
                //we have to traverse the first row
                for(int j=left;j<=right;j++)
                    ans.push_back(matrix[up][j]);
                up++;
                dir=1;
            }
            else if(dir==1){
                //we have to traverse the rigtmost row
                for(int i=up;i<=down;i++)
                    ans.push_back(matrix[i][right]);
                right--;
                dir=2;
            }
            else if(dir==2){
                //we have to traverse the bottom row
                for(int j=right;j>=left;j--)
                    ans.push_back(matrix[down][j]);
                down--;
                dir=3;
            }
            else if(dir==3){
                //we have to print the leftmost row
                for(int i=down;i>=up;i--)
                    ans.push_back(matrix[i][left]);
                left++;
                dir=0;
            }
        }
        return ans;
    }
};


