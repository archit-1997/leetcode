/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestCommonSubsequence.cpp
 * @created     : Friday Oct 01, 2021 21:45:37 IST
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

    int lcs(string &text1,string &text2, int n1, int n2,vector<vector<int>> &dp,int i,int j){
        if(i==n1 || j==n2)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(text1[i]==text2[j])
            dp[i][j]=1+lcs(text1,text2,n1,n2,dp,i+1,j+1);
        else{
            int v1=lcs(text1,text2,n1,n2,dp,i,j+1),v2=lcs(text1,text2,n1,n2,dp,i+1,j);
            dp[i][j]=max(v1,v2);
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();

        vector<vector<int>> dp(n1,vector<int> (n2,-1));

        return lcs(text1,text2,n1,n2,dp,0,0);
    }
};
