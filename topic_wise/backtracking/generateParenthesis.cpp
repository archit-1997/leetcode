/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : generateParenthesis.cpp
 * @created     : Wednesday Jul 28, 2021 10:00:57 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findCombinations(vector<string>&ans,int n,string tmp,int open,int close ){
        //when all the parenthesis have been closed
        if(close==n){
            ans.push_back(tmp);
            return;
        }

        //check if we can open one parenthesis
        if(open<n)
            findCombinations(ans,n,tmp+'(',open+1,close);

        //we can only close if open>close
        if(open>close)
            findCombinations(ans,n,tmp+')',open,close+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp="(";
        findCombinations(ans,n,tmp,1,0);
        return ans;
    }
};
