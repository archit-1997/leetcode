/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : coinChange.cpp
 * @created     : Friday Aug 13, 2021 11:34:59 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n,vector<int> (amount+1,0));

        //first we are calculating for the very first denomination
        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0)
                dp[0][j]=j/coins[0];
            else
                dp[0][j]=INT_MAX;
        }

        //now we will fill for the rest of the row
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i])
                    dp[i][j]=dp[i-1][j];
                else{
                    int v1=dp[i-1][j];
                    int v2;
                    if(dp[i][j-coins[i]]!=INT_MAX)
                        v2=1+dp[i][j-coins[i]];
                    else
                        v2=INT_MAX;
                    dp[i][j]=min(v1,v2);
                }
            }
        }

        if(dp[n-1][amount]==INT_MAX)
            return -1;

        return dp[n-1][amount];

    }
};


