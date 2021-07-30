/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : bestTimeToBuyAndSellStockIII.cpp
 * @created     : Friday Jul 30, 2021 18:59:06 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we have at most 2 transactions
        //k is the number of transactions
        int k=2;
        int n=prices.size();

        //2d dp
        vector<vector<int>> dp(3,vector<int> (n,0));

        for(int i=1;i<=k;i++){
            int maxProfit=dp[i-1][0]-prices[0];
            for(int j=1;j<n;j++){
                //{without any transaction,if we sell on this day
                dp[i][j]=max(dp[i][j-1],prices[j]+maxProfit);
                maxProfit=max(maxProfit,dp[i-1][j]-prices[j]);
            }
        }
        return dp[2][n-1];
    }
};

