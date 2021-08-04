/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : combinationSumII.cpp
 * @created     : Wednesday Aug 04, 2021 22:22:29 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void findCombinations(vector<int> &candidates, int target,int index,vector<int> &tmp,vector<vector<int>> &ans){
        int n=candidates.size();
        if(target<0)
            return;

        if(target==0){
            ans.push_back(tmp);
            return ;
        }
        for(int i=index;i<n;i++){
            if(i==index || candidates[i]!=candidates[i-1]){
                tmp.push_back(candidates[i]);
                findCombinations(candidates,target-candidates[i],i+1,tmp,ans);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        findCombinations(candidates,target,0,tmp,ans);
        return ans;
    }
};
