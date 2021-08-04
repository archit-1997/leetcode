/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : combinationSum.cpp
 * @created     : Wednesday Aug 04, 2021 21:50:09 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findCombinations(vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> &tmp,int index){
            int n=candidates.size();
            if(index==n || target<0)
                return;

            if(target==0){
                ans.push_back(tmp);
                return;
            }

            //go ahead without subtracting
            findCombinations(candidates,target,ans,tmp,index+1);
            //subtract this index and remain on the same index
            tmp.push_back(candidates[index]);
            findCombinations(candidates,target-candidates[index],ans,tmp,index);
            tmp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        findCombinations(candidates,target,ans,tmp,0);
        return ans;
    }
};

