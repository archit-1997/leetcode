/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : paintFence.cpp
 * @created     : Saturday Aug 14, 2021 10:11:15 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n==1)
            return k;
        else if(n==2)
            return (k+k*(k-1));
        else{
             vector<vector<int>> dp(2,vector<int> (n,0));
            dp[0][1]=k;
            dp[1][1]=k*(k-1);
            for(int j=2;j<n;j++){
                //for the two last fences of the same color, we can use the one with last two with different color
                dp[0][j]=dp[1][j-1];
                //for the two with different colors, we can how many we had till this point and then we can just have
                //one less color
                int sum=dp[0][j-1]+dp[1][j-1];
                dp[1][j]=sum*(k-1);
            }
            return dp[0][n-1]+dp[1][n-1];
        }
        
    }
};
