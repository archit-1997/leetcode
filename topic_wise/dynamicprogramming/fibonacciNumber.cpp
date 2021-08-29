/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : fibonacciNumber.cpp
 * @created     : Sunday Aug 29, 2021 18:58:41 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int solve(vector<int> &dp,int n){
        //if we already have the result for the base case
        if(dp[n]!=-1)
            return dp[n];

        //if not calculated
        dp[n]=solve(dp,n-1)+solve(dp,n-2);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        if(n<=1)
            return n;
        dp[0]=0,dp[1]=1;

        return solve(dp,n);
    }
};


