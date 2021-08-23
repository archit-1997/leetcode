/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : wordBreak.cpp
 * @created     : Monday Aug 23, 2021 08:33:14 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool find(string &s,unordered_map<string,int> &count,vector<vector<int>> &dp,int l,int r){

        //we need to have the terminating condition
        if(l>r)
            return true;

        //check if already computed
        if(dp[l][r]!=-1)
            return dp[l][r];

        string str="";
        for(int i=l;i<=r;i++){
            str=str+s[i];
            //check whether this string is in map
            if(count.find(str)!=count.end()){
                //we have found the string in the map
                //mark this as present in the dp
                dp[l][i]=1;

                //find for the remaining string
                if(find(s,count,dp,i+1,r))
                    return true;
            }
        }
        //we haven't found the string
        dp[l][r]=0;
        return false;
    }

    bool isPresent(string &s,unordered_map<string,int> &count){
        int n=s.size();
        //dp vector for memoisation
        vector<vector<int>> dp(n,vector<int> (n,-1));

        bool res=find(s,count,dp,0,n-1);

        return res;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> count;
        int n=wordDict.size();
        for(int i=0;i<n;i++)
            count[wordDict[i]]=1;
        int len=s.size();

        return isPresent(s,count);
    }
};
