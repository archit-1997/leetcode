#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int solve(vector<vector<int>> &dp,vector<int> &prices,int n,int status,int buyPrice,int curIndex){
        
        //no stocks left
        if(n==0)
            return 0;

        if(dp[status][n]>=0)
            return dp[status][n];

        //status 2 : sold in previous , so cooldown
        if(status==2){
            dp[status][n]=solve(dp,prices,n-1,0,0,curIndex+1);
            return dp[status][n];
        }
        else if(status==1){
            return dp[status][n]=max(solve( prices,n-1,status,buyPrice,curIndex+1 ),prices[curIndex]-buyPrice+solve(dp,prices,n-1,2,0,curIndex+1));
            }
            else{
                //yet to buy a stock : so buy now
                dp[status][n]=max(dp[status][n],solve(dp,prices,n-1,1,prices[curIndex],curIndex+1));
            }

        return dp[status][n];
        }
        

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(3,vector<int> (n+1,-1));

        //dp-prices-number of stocks-initial status of transaction-curIndex
        return solve(dp,prices,n,0,0,0);
        
    }
};
