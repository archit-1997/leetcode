/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : combinations.cpp
 * @created     : Thursday Aug 05, 2021 20:19:25 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findSubsets(vector<vector<int>> &ans,vector<int> &tmp,int cur,int len,int n,int k){
        //if we have a valid subset
        if(len==k){
            ans.push_back(tmp);
            return;
        }

        //if we are going out of range
        if(cur>n)
            return;

        //we can exclude the current element
        findSubsets(ans,tmp,cur+1,len,n,k);

        //we can include the current element
        tmp.push_back(cur);
        findSubsets(ans,tmp,cur+1,len+1,n,k);
        tmp.pop_back();

    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        findSubsets(ans,tmp,1,0,n,k);
        return ans;
    }
};
