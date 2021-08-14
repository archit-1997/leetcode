/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : uniqueBinarySearchTrees.cpp
 * @created     : Saturday Aug 14, 2021 10:46:23 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            int sum=0;
            int start=i-1,end=0;
            while(start!=0){
                int val=dp[start]*dp[end];
                sum+=val;
                start--,end++;
            }
            dp[i]=sum;
        }
        return dp[n];
    }
};
