/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : searchA2DMatrix.cpp
 * @created     : Thursday Aug 05, 2021 20:14:22 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();

        //check for the base cases
        if(target>matrix[r-1][c-1] || target<matrix[0][0])
            return false;

        //set the marker for the row
        int count=0;
        while(target>matrix[count][c-1])
            count++;

        //now we have reached the required row
        //we can perform binary search here
        int index=lower_bound(matrix[count].begin(),matrix[count].end(),target)-matrix[count].begin();

        if(matrix[count][index]==target)
            return true;
        return false;
    }
};
