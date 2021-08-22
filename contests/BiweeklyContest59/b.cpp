/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : b.cpp
 * @created     : Saturday Aug 21, 2021 20:11:56 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();

        //we need to find the min number in the matrix and also count of negative numbers in the matrix
        int small=INT_MAX,count=0;
        long long int sum=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int val=matrix[i][j];
                small=min(small,abs(val));
                if(val<0)
                    count++;
                sum+=abs(val);
            }
        }
        if(count%2==0)
            return sum;
        else
            return sum-2*small;
    }
};
