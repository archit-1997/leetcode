#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int hash(int a,int b){
        return (a*27*2)+b;
    }
    
    int countPalindromicSubsequence(string s) {
        //{leftmost,rightmost} occurrence of a character
        vector<vector<int>> dict(26,vector<int> (2,-1));
        int n=s.size();
        for(int i=0;i<n;i++){
            //for every character present in the string
            int index=s[i]-'a';
            //update the leftmost and rightmost index for this character
            if(dict[index][0]==-1)
                dict[index][0]=i;
            else
                dict[index][1]=i;
        }
        
        set<int> st;
        //start computation
        for(int i=1;i<n-1;i++){
            int index=s[i]-'a';
            for(int j=0;j<26;j++){
                //extract leftmost and rightmost index
               int left=dict[j][0],right=dict[j][1];
                if(left!=-1 && right!=-1 && left<i && right>i){
                    //we have found one such palindromic subsequence
                    int digest=hash(j,index);
                    /* string str=to_string(j)+to_string(index)+to_string(j); */
                    st.insert(digest);
                }
            }
        }
        return st.size();
    }
};

