/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : uniquePaths.cpp
 * @created     : Thursday Aug 05, 2021 19:02:18 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,1));
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};
