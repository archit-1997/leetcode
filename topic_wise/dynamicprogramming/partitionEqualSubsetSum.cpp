/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : partitionEqualSubsetSum.cpp
 * @created     : Tuesday Aug 24, 2021 17:54:50 IST
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    bool isPossible(vector<int> &nums,vector<vector<int>> &dp,int index,int sum){
        int n=nums.size();
        //if the sum is zero and we have reached the last index
        if(sum==0 && index==n)
            return true;

        //if we have reached the last index
        if(index==n || sum<0)
            return false;

        //if already calculated for this sum and this index
        if(dp[sum][index]!=-1)
            return dp[sum][index];

        //we can include or exclude a particular index
        bool exc=isPossible(nums,dp,index+1,sum);

        bool inc=isPossible(nums,dp,index+1,sum-nums[index]);

        dp[sum][index]=(exc || inc);

        return dp[sum][index];

    }


    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        //find the sum of all the elements int the array
        sum=accumulate(nums.begin(),nums.end(),sum);

        //if sum is odd
        if(sum&1)
            return false;

        sum/=2;
        vector<vector<int>> dp(sum+1,vector<int>(n,-1));
        return isPossible(nums,dp,0,sum);

    }
};

