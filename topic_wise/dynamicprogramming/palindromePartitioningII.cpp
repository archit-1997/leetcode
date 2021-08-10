/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : palindromePartitioningII.cpp
 * @created     : Monday Aug 09, 2021 09:12:01 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s,int start,int len){
        string str=s.substr(start,len);
        string rev=str;
        reverse(rev.begin(),rev.end());

        return (str==rev);
    }

    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        //dp[i][j] indicates min cuts for s(i-j) both inclusive to make palindromes

        //min cuts for all palindromes of length 2
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1])
                dp[i][i+1]=1;
        }

        //for palindromes of length 3 and above
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                //if this is already a palindrome, then 0 cut
                int start=i,end=i+len-1;
                if(isPalindrome(s,start,len))
                    dp[start][end]=0;
                else{
                    //we will have to find the min cut for this 
                    //for length len,we can have len-1 cuts
                    int cut=len-1;
                    int res=INT_MAX;
                    for(int j=start;j<end;j++)
                        res=min(res,dp[start][j]+dp[j+1][end]);

                    //update ther res
                    dp[start][end]=res;
                }
                
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }

        return dp[0][n-1];
    }
};
