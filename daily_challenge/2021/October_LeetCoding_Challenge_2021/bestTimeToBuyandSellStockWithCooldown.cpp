/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : bestTimeToBuyAndSellStockWithCooldown.cpp
 * @created     : Saturday Jul 31, 2021 11:15:10 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<vector<int>> &dp,vector<int> &prices,bool hasBought,int index){
        if(index>=prices.size())
            return 0;

        if(dp[hasBought][index]!=-1)
            return dp[hasBought][index];

        //if we haven't bought a stock yet
        if(!hasBought){
            //we can either either buy or chose not to buy
            int a=-prices[index]+solve(dp,prices,true,index+1);
            int b=solve(dp,prices,false,index+1);
            return dp[hasBought][index]=max(a,b);
        }

        //if we already have a stock
        int a=prices[index]+solve(dp,prices,false,index+2);
        int b=solve(dp,prices,true,index+1);
        return dp[hasBought][index]=max(a,b);

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(2,vector<int> (n,-1));

        return solve(dp,prices,false,0);
    }
};

