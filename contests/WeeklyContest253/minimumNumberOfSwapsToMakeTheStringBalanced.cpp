/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minimumNumberOfSwapsToMakeTheStringBalanced.cpp
 * @created     : Sunday Aug 08, 2021 08:33:36 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countMinSwaps(stack<int> st,string s){
        int open=0,close=0;
        while(!st.empty()){
            int t=st.top();
            st.pop();
            if(s[t]=='[')
                open++;
            else
                close++;
        }
        int ans=(max(open,close)+1)/2;
        return ans;
    }

    int minSwaps(string s) {
        stack<int> st;
        int n=s.size();

        //first remove the balanced part
        for(int i=0;i<n;i++){
            if(s[i]=='[')
                st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='[')
                    st.pop();
                else
                    st.push(i);
            }
        }

        //this means that the string is already balanced
        if(st.empty())
            return 0;

        int ans=countMinSwaps(st,s);
        return ans;
    }
};
