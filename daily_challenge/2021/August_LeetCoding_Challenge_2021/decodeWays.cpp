/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : decodeWays.cpp
 * @created     : Wednesday Aug 18, 2021 20:55:49 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWays(string s,vector<int> &dp, int index){
        int n=s.size();
        //if we have covered all the elements
        if(index==n)
            return 1;
        if(dp[index]!=0)
            return dp[index];

        int ans=0;
        //finding the result for only 1 character
        if(s[index]!='0')
            ans+=findWays(s,dp,index+1);
        if(index+1<s.size() && (s[index]=='1' || s[index]=='2' && s[index+1]<='6'))
            ans+=findWays(s,dp,index+2);
        dp[index]=ans;
        return dp[index];
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        return findWays(s,dp,0);
    }
};

