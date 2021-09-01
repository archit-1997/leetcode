/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : longestUncommonSubsequenceII.cpp
 * @created     : Wednesday Sep 01, 2021 09:08:40 IST
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
    int findLUSlength(vector<string>& strs) {
        int n=strs.size();

        if(n==0)
            return -1;

        int ans=-1;

        for(int i=0;i<n;i++){
            string s=strs[i];
            int len=s.size();
            bool flag=false;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;

                //if strs[j] is a subsequence of strs[i]: then we need to break
                if(isLCS(s,strs[j])){
                    flag=true;
                    break;
                }
            }
            //if we haven't found a string which is a subsequence of strs[i], then this is the answer
            if(flag==false)
                ans=max(ans,len);
        }
        return ans;
    }

    bool isLCS(string a, string b){
        //we need to check whether a is a subsequence of b or not
        if(b.size()<a.size())
            return false;
        
        int index=0,len=a.size();
        int n=b.size();
        for(int i=0;i<n;i++){
            if(index<len && b[i]==a[index])
                index++;
        }
       
        return (index==len);
    }
};

