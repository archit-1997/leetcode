/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : stoneGame_dp.cpp
 * @created     : Friday Aug 06, 2021 06:17:22 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int> &piles,int l, int r, vector<vector<int>> &dp){
        //base case
        if(dp[l][r]!=-1)
            return dp[l][r];

        //if we have only two values left,we will return the max of these
        if(r-l+1==2){
            dp[l][r]=max(piles[l],piles[r]);
            return dp[l][r];
        }

        //at any moment, we can either select the left one or the right one
        int left=piles[l]+min(solve( piles,l+2,r,dp),solve(piles,l+1,r-1,dp));
        int right=piles[r]+min(solve(piles,l,r-2,dp),solve(piles,l+1,r-1,dp));

        dp[l][r]=max(left,right);

        return dp[l][r];
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        //we can either chose the l or the r one
        return solve(piles,0,n-1,dp);
    }
};
