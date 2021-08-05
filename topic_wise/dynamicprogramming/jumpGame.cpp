/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : jumpGame.cpp
 * @created     : Thursday Aug 05, 2021 09:31:09 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int isReachable(vector<int> &nums,vector<int> &dp,int index){
        int n=nums.size();
        if(index==n-1)
            return 0;

        if(dp[index]!=10001)
            return dp[index];

        for(int i=index+1;i<nums[index]+index;i++){
            dp[index]=min(dp[index],1+isReachable(nums,dp,i));
        }

        return dp[index];
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,10001);
        //min if we can reach the last index from 0th index
        isReachable(nums,dp,0);
        return dp[n-1]!=10001;
    }
};
