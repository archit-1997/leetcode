/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : evaluateReversePolishNotation.cpp
 * @created     : Friday Aug 13, 2021 08:26:05 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int performOperation(int a,int b,string op){
        if(op=="+")
            return b+a;
        else if(op=="-")
            return b-a;
        else if(op=="*")
            return b*a;
        else 
            return b/a;
    }

    int evalRPN(vector<string>& tokens) {
        int ans=0;
        stack<int> st;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int t1=st.top();
                st.pop();
                 int t2=st.top();
                 st.pop();
                 //perform the operation
                 int res=performOperation(t1,t2,tokens[i]);
                 st.push(res);
            }
            else{
                //convert the current string to integer
                int val=stoi(tokens[i]);
                st.push(val);
            }
        }

        return st.top();
    }
};
