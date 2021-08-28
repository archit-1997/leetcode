/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestCommonSubsequence.cpp
 * @created     : Saturday Aug 28, 2021 16:29:13 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<vector<int>> &dp,string &text1,string &text2,int n,int m){
        //if we have reached the end
        if(n<=0 || m<=0)
            return 0;

        //if already computed
        if(dp[n][m]!=-1)
            return dp[n][m];

        //if the current character for both of them is same
        if(text1[n-1]==text2[m-1])
            dp[n][m]=1+solve(dp,text1,text2,n-1,m-1);
        //if current character different
        else{
            int a=solve(dp,text1,text2,n-1,m);
            int b=solve(dp,text1,text2,n,m-1);

            dp[n][m]=max(a,b);
        }
        return dp[n][m];
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

        return solve(dp,text1,text2,n,m);
    }
};
