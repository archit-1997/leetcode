#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //iterative solution
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int> (m,0));


        //populate the first row
        bool flag=false;
        for(int j=0;j<m;j++){
          if(text2[j]==text1[0])
              flag=true;
          if(flag)
            dp[0][j]=1;
        }

        //populate the first col
        flag=false;
        for(int i=0;i<n;i++){
          if(text1[i]==text2[0])
              flag=true;
          if(flag)
            dp[i][0]=1;
        }
        
        for(int i=1;i<text1.size();i++){
            for(int j=1;j<text2.size();j++){
               if(text1[i]==text2[j])
                   dp[i][j]=dp[i-1][j-1]+1;
               else
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
