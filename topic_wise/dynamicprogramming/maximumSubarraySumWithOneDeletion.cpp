/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumSubarraySumWithOneDeletion.cpp
 * @created     : Wednesday Aug 04, 2021 05:54:59 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(3,vector<int> (n,INT_MIN));

        //0:with deletion
        //1: without deletion
        //2: max(0,1)
        
        //base case 
        //without including the first element
        dp[0][0]=0;
        //including the first element
        dp[1][0]=arr[0];
        //max of these two
        dp[2][0]=max(dp[0][0],dp[1][0]);
        
        for(int i=1;i<n;i++){
            //not including the first element
            dp[0][i]=max(dp[1][i-1],dp[0][i-1]+arr[i]);

            //including this element
            dp[1][i]=max(arr[i],dp[1][i-1]+arr[i]);
            dp[2][i]=max(dp[2][i-1],max(dp[0][i],dp[1][i]));

        }
        return dp[2][n-1];
    }
};

