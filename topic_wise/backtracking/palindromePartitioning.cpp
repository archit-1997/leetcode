/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : palindromePartitioning.cpp
 * @created     : Monday Aug 09, 2021 08:16:16 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findPartitions(string &s,vector<vector<int>> &dp,vector<vector<string>> &ans,vector<string> tmp,int index){
        int n=s.size();
        //if we have traversed the complete string
        if(index>=n){
            ans.push_back(tmp);
            return;
        }

        for(int len=1;len<=n-index;len++){
            int start=index,end=index+len-1;
            //if the current substring is a palindrome
            if(dp[start][end]){
                string str=s.substr(start,len);
                tmp.push_back(str);
                findPartitions(s,dp,ans,tmp,end+1);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));

        //dp i,i is always a palindrome : single character
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        //marking palindromes of length 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                dp[i][i+1]=1;
        }

        //starting from palindromes of length 3 and above
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int start=i,end=i+len-1;
                if(s[start]==s[end] && dp[start+1][end-1])
                    dp[start][end]=1;
            }
        }

        //find all plaindromic partitions
        vector<vector<string>> ans;
        vector<string> tmp;
        findPartitions(s,dp,ans,tmp,0);

        return ans;


    }
};
