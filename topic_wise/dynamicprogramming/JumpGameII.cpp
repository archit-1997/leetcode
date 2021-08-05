/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : jumpGameII.cpp
 * @created     : Thursday Aug 05, 2021 09:02:52 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findMinSteps(vector<int> &nums,vector<int> &dp,int index){
        int n=nums.size();
        if(index>=n-1)
            return 0;

        if(dp[index]!=10001)
            return dp[index];

        for(int i=index+1;i<=nums[index]+index;i++){
            //min steps to reach n-1 from index is 
            //1+min number of steps from those indices which are reachable via index
            dp[index]=min(dp[index],1+findMinSteps(nums,dp,i));
        }

        return dp[index];


    }

    int jump(vector<int>& nums) {       
        int n=nums.size();

        //dp[i]-> min number of steps required to reach n-1 from index i
        vector<int> dp(n,10001);

        return findMinSteps(nums,dp,0);
    }
};

