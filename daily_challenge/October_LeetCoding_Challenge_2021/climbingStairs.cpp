/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : climbingStairs.cpp
 * @created     : Tuesday Oct 05, 2021 19:36:10 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;

        vector<int> dp(n+1,0);

        dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];

        return dp[n];
    }
};
